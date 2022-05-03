// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/LimeLightTracking.h"

LimeLightTracking::LimeLightTracking(LimeLightSubsystem* camera, TurretSubsystem* turretsys): limelight{camera}, turret{turretsys} {
  AddRequirements(limelight);
  AddRequirements(turret);
}

// Called when the command is initially scheduled.
void LimeLightTracking::Initialize() {}

double limelightLast;

// Called repeatedly when this Command is scheduled to run
void LimeLightTracking::Execute() {
  // Velocity tracking while limelight has a target
  if(limelight->hasTarget() && turret->get() >-110 && turret->get() < 110){
    turret->setVel((limelight->getX() - limelightLast)*50);
    limelightLast = limelight->getX();
  }
  // Move Left to right when limelight does not have a target
  else{
    if(turret->get() < -100){
      turret->set(120);
    }
    else if(turret->get() > 100){
      turret->set(-120);
    }
  }
}

// Called once the command ends or is interrupted.
void LimeLightTracking::End(bool interrupted) {
  turret->drive(ControlMode::PercentOutput, 0);
}

// Returns true when the command should end.
bool LimeLightTracking::IsFinished() {
  return false;
}
