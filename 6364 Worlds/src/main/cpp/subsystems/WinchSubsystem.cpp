// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/WinchSubsystem.hpp"
#include "Constants.h"
#include "tools/Motors.hpp"

WinchSubsystem::WinchSubsystem() : 
    WinchMotor{RobotMap::CAN::WinchMtr}, 
    lowerLimit{RobotMap::DIGITAL::Hang_Limit_LOWER} 
{
    motorConfiguration::Talon::winchMotor(WinchMotor);
}

void WinchSubsystem::set(double velocity){
    WinchMotor.Set(ControlMode::Velocity, velocity);
}

void WinchSubsystem::set(ControlMode mode, double iPow){
    WinchMotor.Set(mode, iPow);
}

void WinchSubsystem::setMode(NeutralMode neutralMode){
    WinchMotor.SetNeutralMode(neutralMode);
}

double WinchSubsystem::getPercentOutput(){
    return WinchMotor.GetMotorOutputPercent();
}

double WinchSubsystem::getVelocity(){
    return WinchMotor.GetSelectedSensorVelocity();
}

double WinchSubsystem::getPosition(){
    return WinchMotor.GetSelectedSensorPosition();
}

void WinchSubsystem::resetPosition(){
    WinchMotor.SetSelectedSensorPosition(0);
}

void WinchSubsystem::resetPosition(double zero){
    WinchMotor.SetSelectedSensorPosition(zero);
}

bool WinchSubsystem::getLowerLimit(){
    return lowerLimit.Get();
}

// This method will be called once per scheduler run
void WinchSubsystem::Periodic() {}
