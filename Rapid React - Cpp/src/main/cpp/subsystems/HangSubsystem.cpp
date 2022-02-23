#include "subsystems/HangSubsystem.hpp"
#include "Constants.h"
#include "utilities/Talon.hpp"

HangSubsystem::HangSubsystem() : winchMtr{RobotMap::CAN::HangMtr}, clawMtr{RobotMap::CAN::ClawMtr}, pdp{}{
    TalonConfiguation::winchMotor(winchMtr);
    TalonConfiguation::winchMotor(clawMtr);
};

void HangSubsystem::setWinch(ControlMode mode, double iPow){
    winchMtr.Set(mode, iPow);
}

double HangSubsystem::getWinch(){
    return winchMtr.GetSelectedSensorPosition();
}

double HangSubsystem::getWinchDraw() const{
    return pdp.GetCurrent(RobotMap::PDP::WinchPort);
}

void HangSubsystem::setClaw(ControlMode mode, double iPow){
    clawMtr.Set(mode, iPow);
}

double HangSubsystem::getClaw(){
    return clawMtr.GetSelectedSensorPosition();
}