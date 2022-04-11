/**
 * @file WinchSubsystem.cpp
 * @author Jacob Chisholm
 * @brief Winch Subsystem
 * @version 1.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 * Winch Subsystem:
 *  Designed for the Ten Ton Robotics 2022 FRC Robot,
 *  Contains one (1) Falcon 500 Motor acting as the Winch
 *  Contains one (1) Single Action solenoid for Raising the Hook Bar
 *  Contains one (1) Lower Bound Limit Switch used to stop the winch fom pulling down to far
 *  
 *  Works in parallel with the Claw Subsystem
 * 
 *  Default Command:
 *    HangCommands/Pneumatic Control
 *          - Controller Operation to fire the single action solenoid
 * 
 */

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/WinchSubsystem.hpp"
#include "Constants.h"
#include "tools/Motors.hpp"
#include <frc/PneumaticsModuleType.h>
#include <frc/smartdashboard/SmartDashboard.h>

WinchSubsystem::WinchSubsystem() : 
    WinchMotor{RobotMap::CAN::WinchMtr}, 
    lowerLimit{RobotMap::DIGITAL::Hang_Limit_LOWER},
    solenoid{frc::PneumaticsModuleType::CTREPCM, RobotMap::PCM::armPiston}
{
    motorConfiguration::Talon::winchMotor(WinchMotor);
    SetName("Winch");
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
    return !lowerLimit.Get();
}

void WinchSubsystem::setSolenoid(bool state){
    solenoid.Set(state);
}

bool WinchSubsystem::getSolenoid(){
    return solenoid.Get();
}

void WinchSubsystem::Periodic(){
    frc::SmartDashboard::PutNumber("Winch RPM", c_TalonRPM(WinchMotor.GetSelectedSensorVelocity()));
    frc::SmartDashboard::PutNumber("Winch Amps", WinchMotor.GetSupplyCurrent());
    frc::SmartDashboard::PutBoolean("Hang Limit", getLowerLimit());
}
