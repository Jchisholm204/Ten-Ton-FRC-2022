// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/LimeLightTracking.h"
#include "Constants.h"

LimeLightTracking::LimeLightTracking(LimeLightSubsystem* camera, TurretSubsystem* turretsys): limelight{camera}, turret{turretsys} {
  AddRequirements(limelight);
  AddRequirements(turret);
}

// Called when the command is initially scheduled.
void LimeLightTracking::Initialize() {
    error = {0};
    error_prior = {0};
    integral = {0};
    integral_prior = {0};
    derivitive = {0};
    output = {0};
}

// Called repeatedly when this Command is scheduled to run
void LimeLightTracking::Execute() {
  // Engage Tracking while limelight has a target and turret is within bounds
  if(limelight->hasTarget() && turret->get() >-110 && turret->get() < 110){

    error = -(limelight->getX()/27);

    integral = integral_prior + error*20;
    
    derivitive = (error-error_prior)/20;

    output = Turret::kP*error + Turret::kI*integral + Turret::kD*derivitive;

    output < -100 ? output = -100 : output > 100 ? output = 100 : output;

    output /= 100;

    turret->drive(ControlMode::PercentOutput, output);

    integral_prior = integral;
    error_prior = error;

  }
  // Move Left to right when limelight does not have a target
  else{
    if(turret->get() < -100){
      turret->set(110);
    }
    else if(turret->get() > 100){
      turret->set(-110);
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
