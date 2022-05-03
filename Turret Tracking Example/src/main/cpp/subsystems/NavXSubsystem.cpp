// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/NavXSubsystem.h"

NavXSubsystem::NavXSubsystem(){
    sensor1.Calibrate();
}

double NavXSubsystem::getYaw(){
    return sensor1.GetYaw();
}

double NavXSubsystem::getYawVelocity(){
    return (getYaw() - lastYaw)*50;
}

void NavXSubsystem::calibrate(){
    sensor1.Calibrate();
}

void NavXSubsystem::reset(){
    sensor1.Reset();
}

double NavXSubsystem::getYawRadians(){
    return sensor1.GetYaw()*3.14159/180;
}

double NavXSubsystem::getYawVelocityRadians(){
    return ((getYaw() - lastYaw)*50)*3.14159/180;
}

// This method will be called once per scheduler run
void NavXSubsystem::Periodic() {
    lastYaw = getYaw();
}
