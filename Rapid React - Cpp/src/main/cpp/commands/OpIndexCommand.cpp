#include "commands/OpIndexCommand.hpp"
#include "RobotContainer.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <frc/Timer.h>

OpIndexCommand::OpIndexCommand(IndexSubsystem* SubSystem_index) : index{SubSystem_index} {
    AddRequirements(index);
}

void OpIndexCommand::Execute(){

    frc::SmartDashboard::PutNumber("Codex: ", index->getCodex());
    frc::SmartDashboard::PutBoolean("Top PE Sensor: ", index->getTopSensor());
    frc::SmartDashboard::PutBoolean("Bottom PE Sensor: ", index->getBotSensor());

    if(master.GetRightBumper()){
        index->shoot(1);
        //waitSaveTime = getClock();
    }
    else if(master.GetLeftBumper()){
        index->setTop(ControlMode::PercentOutput, -0.5);
        index->setBot(ControlMode::PercentOutput, -0.5);
    }
    else{
        index->runCodex();
    }

    //Run Feeder Motor (Sideways Index Module)
    if(index->getCodex() == 2){
        index->setFeed(ControlMode::PercentOutput, 0.1); //Slow down when index full
    }
    else{
        index->setFeed(ControlMode::PercentOutput, 1);
    }
}

void OpIndexCommand::End(bool interrupted){
    index->stop();
}