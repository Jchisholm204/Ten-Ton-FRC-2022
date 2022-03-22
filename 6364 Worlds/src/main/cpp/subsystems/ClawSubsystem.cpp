// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ClawSubsystem.hpp"
#include "Constants.h"
#include "tools/Motors.hpp"

ClawSubsystem::ClawSubsystem() : 
    ClawMotor{RobotMap::CAN::ClawMtr}, 
    lowerLimit{0},
    upperLimit{0}
{
    motorConfiguration::Talon::clawMotor(ClawMotor);
}

void ClawSubsystem::set(double velocity){
    ClawMotor.Set(ControlMode::Velocity, velocity);
}

void ClawSubsystem::set(ControlMode mode, double iPow){
    ClawMotor.Set(mode, iPow);
}

void ClawSubsystem::setMode(NeutralMode neutralMode){
    ClawMotor.SetNeutralMode(neutralMode);
}

double ClawSubsystem::getPercentOutput(){
    return ClawMotor.GetMotorOutputPercent();
}

double ClawSubsystem::getVelocity(){
    return ClawMotor.GetSelectedSensorVelocity();
}

double ClawSubsystem::getPosition(){
    return ClawMotor.GetSelectedSensorPosition();
}

void ClawSubsystem::resetPosition(){
    ClawMotor.SetSelectedSensorPosition(0);
}

void ClawSubsystem::resetPosition(double zero){
    ClawMotor.SetSelectedSensorPosition(zero);
}

bool ClawSubsystem::getLowerLimit(){
    return lowerLimit.Get();
}

bool ClawSubsystem::getUpperLimit(){
    return upperLimit.Get();
}

// This method will be called once per scheduler run
void ClawSubsystem::Periodic() {}
