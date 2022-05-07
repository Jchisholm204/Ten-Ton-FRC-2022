// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShooterSubsystem.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"

ShooterSubsystem::ShooterSubsystem() = default;

bool ShooterSubsystem::TargetLock(){
    return abs(nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("tx", -50)) < 5;
}

void ShooterSubsystem::setFlyWheel(ControlMode mode, double power){
    flywheelMotor.Set(mode, power);
}

void ShooterSubsystem::setFlyWheel(double velocity){
    flywheelMotor.Set(ControlMode::Velocity, velocity);
}

void ShooterSubsystem::setBackSpin(ControlMode mode, double power){
    backspinMotor.Set(mode, power);
}

void ShooterSubsystem::setBackSpin(double velocity){
    backspinMotor.Set(ControlMode::Velocity, velocity);
}

void ShooterSubsystem::setFeed(ControlMode mode, double power){
    feedMotor.Set(mode, power);
}

void ShooterSubsystem::setFeed(double percentOutput){
    feedMotor.Set(ControlMode::PercentOutput, percentOutput);
}

// This method will be called once per scheduler run
void ShooterSubsystem::Periodic() {}
