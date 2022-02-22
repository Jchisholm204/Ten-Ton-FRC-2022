// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/OpIntakeCommand.hpp"
#include "RobotContainer.h"

OpIntakeCommand::OpIntakeCommand(IntakeSubsystem* SubSystem_intake) : intake{SubSystem_intake} {
    AddRequirements(intake);
}


void OpIntakeCommand::Initialize(){
    intake->startCompressor();
}

void OpIntakeCommand::Execute(){

    if(master.GetAButton()){
        intake->setFront(ControlMode::PercentOutput, 1);   
    }
    else if(master.GetBButton()){
        intake->setFront(ControlMode::PercentOutput, -1);
    }
    else{
        intake->setFront(ControlMode::PercentOutput, 0);
    }

    if(master.GetXButton()){
        intake->setRear(ControlMode::PercentOutput, 1);   
    }
    else if(master.GetYButton()){
        intake->setRear(ControlMode::PercentOutput, -1);
    }
    else{
        intake->setRear(ControlMode::PercentOutput, 0);
    }
}

void OpIntakeCommand::End(bool interrupted){
    intake->stopCompressor();
    intake->setFront(ControlMode::PercentOutput, 0);
    intake->setRear(ControlMode::PercentOutput, 0);
}

bool OpIntakeCommand::IsFinished(){
    return false;
}