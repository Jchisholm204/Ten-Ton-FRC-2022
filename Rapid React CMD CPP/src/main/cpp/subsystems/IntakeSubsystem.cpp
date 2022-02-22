// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IntakeSubsystem.hpp"
#include "utilities/Talon.hpp"
#include "Constants.h"

IntakeSubsystem::IntakeSubsystem() : 
frontMtr{RobotMap::CAN::Intake_front}, 
rearMtr{RobotMap::CAN::Intake_rear},
frontPiston{frc::PneumaticsModuleType::CTREPCM, RobotMap::PCM::frontIntake},
rearPiston{frc::PneumaticsModuleType::CTREPCM, RobotMap::PCM::rearIntake},
compressor{frc::PneumaticsModuleType::CTREPCM}
{
  TalonConfiguation::intake(frontMtr, true);
  TalonConfiguation::intake(rearMtr, false);
}

void IntakeSubsystem::setFront(ControlMode mode, double mPow){
  frontMtr.Set(mode, mPow);
}

void IntakeSubsystem::setRear(ControlMode mode, double mPow){
  rearMtr.Set(mode, mPow);
}

double IntakeSubsystem::getFrontPow(){
  return frontMtr.GetMotorOutputPercent();
}

double IntakeSubsystem::getRearPow(){
  return rearMtr.GetMotorOutputPercent();
}

void IntakeSubsystem::raise(bool front, bool rear){
  if(front == true){
    frontPiston.Set(false);
  }
  if(rear == true){
    rearPiston.Set(false);
  }
}

void IntakeSubsystem::raise(){
  frontPiston.Set(false);
  rearPiston.Set(false);
}

void IntakeSubsystem::lower(bool front, bool rear){
    if(front == true){
    frontPiston.Set(true);
  }
  if(rear == true){
    rearPiston.Set(true);
  }
}

void IntakeSubsystem::lower(){
  frontPiston.Set(true);
  rearPiston.Set(true);
}

bool IntakeSubsystem::getFrontState(){
  return frontPiston.Get();
}

bool IntakeSubsystem::getRearState(){
  return rearPiston.Get();
}

void IntakeSubsystem::startCompressor(){
  compressor.EnableDigital();
}

void IntakeSubsystem::stopCompressor(){
  compressor.Disable();
}
