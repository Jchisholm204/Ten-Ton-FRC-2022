#include "subsystems/HangSubsystem.hpp"
#include "Constants.h"
#include "utilities/Talon.hpp"

HangSubsystem::HangSubsystem() : winchMtr(RobotMap::CAN::HangMtr) {
    TalonConfiguation::winchMotor(winchMtr);
};

void HangSubsystem::setWinch(ControlMode mode, double iPow){
    winchMtr.Set(mode, iPow);
}