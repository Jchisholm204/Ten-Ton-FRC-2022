#include "subsystems/HangSubsystem.hpp"
#include "Constants.h"
#include "utilities/Talon.hpp"

HangSubsystem::HangSubsystem() : winchMtr{RobotMap::CAN::WinchMtr}, clawMtr{RobotMap::CAN::ClawMtr}, arm{frc::PneumaticsModuleType::CTREPCM, RobotMap::PCM::armPiston} {
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

void HangSubsystem::ApplyPressure(bool on){
    arm.Set(on);
}

bool HangSubsystem::GetPressure(){
    return arm.Get();
}