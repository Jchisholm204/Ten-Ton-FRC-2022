// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IntakeCommands/OpIntake.hpp"
#include "RobotContainer.h"
#include <frc/DriverStation.h>


IntakeCommands::OpIntake::OpIntake(IntakeSubsystem* SubSystem_intake) : intake{SubSystem_intake} {
    AddRequirements(intake);
}


void IntakeCommands::OpIntake::Initialize(){
        if(compressor.Enabled() == false){
        printf("Intake Error: Compressor Not Enabled\n");
            if(compressor.GetPressureSwitchValue() == false){
                printf("Tank Pressure Nominal");
            }
        }
        else if(compressor.GetPressureSwitchValue()){
            printf("WARNING: Tank Pressure Low\n");
        }
}

void IntakeCommands::OpIntake::Execute(){

    if(master.GetPOV(0) == 270 || partner.GetPOV(0) == 270){
        intake->raise(false, true);
    }
    else if(master.GetPOV(0) == 90 || partner.GetPOV(0) == 90){
        intake->raise(true, false);
    }

    if(master.GetRightTriggerAxis() > 0.1 || partner.GetRightTriggerAxis() > 0.1){
        intake->setFront(ControlMode::PercentOutput, 1);
        intake->lower(true, false);
    }
    else if(master.GetXButton()){
        intake->setFront(ControlMode::PercentOutput, -1);
        intake->lower(true, false);
    }
    else{
        intake->setFront(ControlMode::PercentOutput, 0);
    }

    if(master.GetLeftTriggerAxis() > 0.1 || partner.GetLeftTriggerAxis() > 0.1){
        intake->setRear(ControlMode::PercentOutput, 1);
        intake->lower(false, true);  
    }
    else if(master.GetYButton()){
        intake->setRear(ControlMode::PercentOutput, -1);
        intake->lower(false, true);
    }
    else{
        intake->setRear(ControlMode::PercentOutput, 0);
    }
}

void IntakeCommands::OpIntake::End(bool interrupted){
    intake->setFront(ControlMode::PercentOutput, 0);
    intake->setRear(ControlMode::PercentOutput, 0);
    intake->raise();
}

bool IntakeCommands::OpIntake::IsFinished(){
    return false;
}