// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/TurretSubsystem.h"

TurretSubsystem::TurretSubsystem(){
    ConfigTurretMotor();
}

void TurretSubsystem::ConfigTurretMotor(){
    // Create the Motor Configuration
    TalonSRXConfiguration motorConfig;
    // Set the Primary Feedback Sensor (configure the motor's encoder)
    motorConfig.primaryPID.selectedFeedbackSensor = FeedbackDevice::CTRE_MagEncoder_Absolute;
    // Configure the Motor's Integrated PID
    motorConfig.slot0.kP = 1.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kI = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kD = 10.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kF = 0.0505; // kF - Feed Forward Value - The Minimum Motor Power Required to Move the Motor

    motorConfig.slot0.integralZone = 0;
    motorConfig.slot0.allowableClosedloopError = 0;
    motorConfig.closedloopRamp = 0.01;

    motorConfig.motionAcceleration = 200;
    motorConfig.motionCruiseVelocity = 22000; //Maximum Speed (encoder units / 100ms) for Magic Motion

    motorConfig.nominalOutputForward = 0.0;
    motorConfig.nominalOutputReverse = 0.0;
    motorConfig.peakOutputForward = 0.4;
    motorConfig.peakOutputReverse = -0.4;

    motorConfig.motionCurveStrength = 0;
    
    // Reset the Motor to Factory Settings before Applying Profile
    TurretMotor.ConfigFactoryDefault();
    // Apply our Motor Configuration Profile
    TurretMotor.ConfigAllSettings(motorConfig);
    //Set the Motor Inversion
    TurretMotor.SetInverted(true);
    //Set the Motors Neutral Mode (What it does when no power is being applied)
    TurretMotor.SetNeutralMode(NeutralMode::Brake);
}

void TurretSubsystem::drive(ControlMode mode, double power){
    TurretMotor.Set(mode, power);
}

void TurretSubsystem::setVel(double degVel){
    TurretMotor.Set(ControlMode::Velocity, (degVel/360)*4096);
}

void TurretSubsystem::set(double deg){
    TurretMotor.Set(ControlMode::MotionMagic, ((deg-180)/180)*4096);
}

void TurretSubsystem::setRads(double rads){
    rads = (rads*180)/3.14159;
    TurretMotor.Set(ControlMode::MotionMagic, ((rads-180)/180)*4096);
}

double TurretSubsystem::get(){
    return ((abs(int(TurretMotor.GetSelectedSensorPosition()))%4096)*360/4096)-180;
}

double TurretSubsystem::getRads(){
    return (((abs(int(TurretMotor.GetSelectedSensorPosition()))%4096)*360/4096)-180)*3.14159/180;
}

// This method will be called once per scheduler run
void TurretSubsystem::Periodic() {}
