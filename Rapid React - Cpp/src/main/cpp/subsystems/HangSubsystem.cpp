#include "subsystems/HangSubsystem.hpp"
#include "Constants.h"
#include "utilities/Talon.hpp"
#include "RobotContainer.h"

HangSubsystem::HangSubsystem() : winchMtr{RobotMap::CAN::HangMtr}, clawMtr{RobotMap::CAN::ClawMtr} {
    TalonConfiguation::winchMotor(winchMtr);
    TalonConfiguation::clawMotor(clawMtr);
}

void HangSubsystem::setWinch(ControlMode mode, double iPow){
    winchMtr.Set(mode, iPow);
}

double HangSubsystem::getWinch(){
    return winchMtr.GetSelectedSensorPosition();
}

double HangSubsystem::getWinchRPM(){
    return c_TalonRPM(winchMtr.GetSelectedSensorVelocity());
}

double HangSubsystem::getWinchDraw() {
    return winchMtr.GetSupplyCurrent();
}

void HangSubsystem::setClaw(ControlMode mode, double iPow){
    clawMtr.Set(mode, iPow);
}

double HangSubsystem::getClaw(){
    return clawMtr.GetSelectedSensorPosition();
}

double HangSubsystem::getClawRPM(){
    return c_TalonRPM(clawMtr.GetSelectedSensorVelocity());
}