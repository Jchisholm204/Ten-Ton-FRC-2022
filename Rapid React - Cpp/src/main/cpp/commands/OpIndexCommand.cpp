#include "commands/OpIndexCommand.hpp"
#include "RobotContainer.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <frc/Timer.h>
#include "Constants.h"

int status_running = 0;

OpIndexCommand::OpIndexCommand(IndexSubsystem* SubSystem_index) : index{SubSystem_index} {
    AddRequirements(index);
}

void OpIndexCommand::Initialize(){
    waitSaveTime = frc::Timer::GetFPGATimestamp() - indexConstants::k_shootTime;
}

void OpIndexCommand::Execute(){

    frc::SmartDashboard::PutNumber("Codex: ", index->getCodex());
    frc::SmartDashboard::PutBoolean("Top PE Sensor: ", index->getTopSensor());
    frc::SmartDashboard::PutBoolean("Bottom PE Sensor: ", index->getBotSensor());
    frc::SmartDashboard::PutBoolean("Index Enabled: ", status_running);

    //Allows Partner Controller To Stop all index control (including shooting)
    if(partner.GetLeftBumperPressed() && status_running == status::OFF){
        status_running = status::RUNNING;
    }
    else if(partner.GetLeftBumperPressed() && status_running == status::RUNNING){
        status_running = status::OFF;
    }

    // Use Status Running to Stop All Indexing (on/true by default)
    if(status_running != status::OFF){
    if(frc::Timer::GetFPGATimestamp() < (waitSaveTime + indexConstants::k_shootTime)){

    }
    else if(master.GetRightBumperPressed()){ // Shoot 2 Balls
        index->shoot(1);
        waitSaveTime = frc::Timer::GetFPGATimestamp();
        status_running = status::SHOOT;
    }
    else if(master.GetLeftBumperPressed()){ // Shoot Top Ball Only
        index->setTop(ControlMode::PercentOutput, 1);
        index->setBot(ControlMode::PercentOutput, 0);
        index->resetCodex();
        status_running = status::SHOT;
        waitSaveTime = frc::Timer::GetFPGATimestamp()+units::time::second_t{1};
    }
    else{
        status_running = status::RUNNING;
        index->runCodex(0.6);
    }

    //Run Feeder Motor (Sideways Index Module)
    if(index->getCodex() == 2){
        index->setFeed(ControlMode::PercentOutput, 0.1); //Slow down when index full
    }
    else{
        index->setFeed(ControlMode::PercentOutput, 1);
    }} //END Status Running

    else{ //Status != running
        status_running = status::OFF;
        //Stop All Indexers if Not Running Codex/Indexing Program
        if(partner.GetRightBumper()){
            index->setTop(ControlMode::PercentOutput, 0);
            index->setBot(ControlMode::PercentOutput, -1);
            index->setFeed(ControlMode::PercentOutput, -1);
        }
        else{
            index->stop();
        }
    }
}

void OpIndexCommand::End(bool interrupted){
    index->stop();
}