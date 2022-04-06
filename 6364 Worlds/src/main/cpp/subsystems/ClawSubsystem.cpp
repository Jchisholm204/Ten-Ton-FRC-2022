// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ClawSubsystem.hpp"
#include "Constants.h"
#include "tools/Motors.hpp"
#include <frc/smartdashboard/SmartDashboard.h>

ClawSubsystem::ClawSubsystem() : 
    ClawMotor{RobotMap::CAN::ClawMtr}, 
    Potentiometer{RobotMap::ANALOG::ClawPOT},
    lowerLimit{RobotMap::DIGITAL::ClawLowerLimit},
    upperLimit{RobotMap::DIGITAL::ClawUpperLimit}
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

double ClawSubsystem::getPot(){
    return Potentiometer.GetValue();
}

double ClawSubsystem::getScaledPosition(){
    return (1-((getPot()-840)/2800))*100;
}

int ClawSubsystem::getVirtualLimit(){
    int virtualLimit = 0;
    if(getPot() > 3590){
        virtualLimit = -1;
    }
    if(getPot() < 800){
        virtualLimit = 1;
    }
    return virtualLimit;
}

bool ClawSubsystem::getLowerLimit(){
    return !lowerLimit.Get();
}

bool ClawSubsystem::getUpperLimit(){
    return !upperLimit.Get();
}

// This method will be called once per scheduler run
void ClawSubsystem::Periodic() {
    frc::SmartDashboard::PutBoolean("Claw Limit", getLowerLimit());
    frc::SmartDashboard::PutNumber("Claw Amps", ClawMotor.GetSupplyCurrent());
    frc::SmartDashboard::PutNumber("Claw Pot", getPot());
    frc::SmartDashboard::PutNumber("Claw Position", getScaledPosition());
}
