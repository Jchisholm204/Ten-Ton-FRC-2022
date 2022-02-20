#include "index.hpp"
#include "Container.hpp"
#include "ports.h"

TalonSRX topMtr(CAN_Index_Top);
TalonSRX botMtr(CAN_Index_Bot);
TalonSRX feedMtr(CAN_Index_Feed);

frc::AnalogInput topPE(ANALOG_Index_TopPE);
frc::AnalogInput bottomPE(ANALOG_Index_BottomPE);

Index::Index(){
    codex = 0;
};

void set(ControlMode mode, double Mpow){
    topMtr.Set(mode, Mpow);
    botMtr.Set(mode, Mpow);
}

void setTop(ControlMode mode, double Mpow){
    topMtr.Set(mode, Mpow);
}

void setBot(ControlMode mode, double Mpow){
    botMtr.Set(mode, Mpow);
}

void setFeed(ControlMode mode, double Mpow){
    feedMtr.Set(mode, Mpow);
}

int Index::getCodex(){
    return codex;
}

void Index::resetCodex(){
    codex=0;
}

bool Index::getTopSensor(){
    return topPE.GetValue() > 1000;
}

bool Index::getBotSensor(){
    return bottomPE.GetValue() > 1000;
}

void Index::stop(){
    topMtr.Set(ControlMode::PercentOutput, 0);
    botMtr.Set(ControlMode::PercentOutput, 0);
}

void Index::stopAll(){
    stop();
    feedMtr.Set(ControlMode::PercentOutput, 0);
}

void Index::runCodex(double Mpow){

    if ( codex == 0 && getTopSensor() ) { codex = 1; };
    if ( codex == 1 && getBotSensor() ) { codex = 2; };

    if( codex == 2 ) {
        topMtr.Set(ControlMode::PercentOutput, 0);
        botMtr.Set(ControlMode::PercentOutput, 0);
    }
    else if ( codex == 1) {
        topMtr.Set(ControlMode::PercentOutput, 0);
        botMtr.Set(ControlMode::PercentOutput, Mpow);
    }
    else {
        topMtr.Set(ControlMode::PercentOutput, Mpow);
        botMtr.Set(ControlMode::PercentOutput, Mpow);      
    }

}