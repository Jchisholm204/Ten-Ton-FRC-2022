#include "subsystems/IndexSubsystem.hpp"
#include "utilities/Talon.hpp"
#include "Constants.h"

IndexSubsystem::IndexSubsystem() : 
    topMtr(RobotMap::CAN::TopIndex),
    botMtr(RobotMap::CAN::BottomIndex),
    feedMtr(RobotMap::CAN::FeedIndex),
    topPE(RobotMap::ANALOG::topPE),
    botPE(RobotMap::ANALOG::botPE)  {
        codex = 0;
    TalonConfiguation::index(topMtr, true);
    TalonConfiguation::index(botMtr, true);
    TalonConfiguation::index(feedMtr, true);
}

void IndexSubsystem::shoot(double iPow){
    topMtr.Set(ControlMode::PercentOutput, iPow);
    botMtr.Set(ControlMode::PercentOutput, iPow);
    codex = 0;
}

void IndexSubsystem::runCodex(){
        double iPow = 0.6;
        if ( getTopSensor() && codex == 0){ codex = 1; };
        if ( getBotSensor() && codex == 1 ){ codex = 2; };

        if ( codex == 2 ){
            topMtr.Set(ControlMode::PercentOutput, 0);
            botMtr.Set(ControlMode::PercentOutput, 0);
        }
        else if ( codex == 1 ){
            topMtr.Set(ControlMode::PercentOutput, 0);
            botMtr.Set(ControlMode::PercentOutput, iPow);
        }
        else if ( codex == 0 ){
            topMtr.Set(ControlMode::PercentOutput, iPow);
            botMtr.Set(ControlMode::PercentOutput, iPow);
        }
        else{
            printf("Codex OverFlow");
            codex = 0;
        }
}

void IndexSubsystem::resetCodex(){
    codex = 0;
}

int IndexSubsystem::getCodex(){
    return codex;
}

void IndexSubsystem::setTop(ControlMode mode, double iPow){
    topMtr.Set(mode, iPow);
}

void IndexSubsystem::setBot(ControlMode mode, double iPow){
    botMtr.Set(mode, iPow);
}

void IndexSubsystem::setFeed(ControlMode mode, double iPow){
    feedMtr.Set(mode, iPow);
}

void IndexSubsystem::stop(){
    topMtr.Set(ControlMode::PercentOutput, 0);
    botMtr.Set(ControlMode::PercentOutput, 0);
    feedMtr.Set(ControlMode::PercentOutput, 0);
}

void IndexSubsystem::stopShoot(){
    topMtr.Set(ControlMode::PercentOutput, 0);
    botMtr.Set(ControlMode::PercentOutput, 0);
}

void IndexSubsystem::stopTop(){
    topMtr.Set(ControlMode::PercentOutput, 0);
}

void IndexSubsystem::stopBot(){
    botMtr.Set(ControlMode::PercentOutput, 0);
}

void IndexSubsystem::stopFeed(){
    feedMtr.Set(ControlMode::PercentOutput, 0);
}

bool IndexSubsystem::getTopSensor(){
    return topPE.GetValue() > 1000;
}

bool IndexSubsystem::getBotSensor(){
    return botPE.GetValue() > 1000;
}

double IndexSubsystem::getTopMtrRPM() {
    double rawVelocity = topMtr.GetSensorCollection().GetIntegratedSensorVelocity();
    return rawVelocity / 2048.0 * 10.0 * 60.0;
}