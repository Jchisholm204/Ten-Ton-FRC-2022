// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/LimeLightSubsystem.h"
#include "subsystems/TurretSubsystem.h"

/**
 * Turret Tracking Using LimeLight
 * 
 * The Most Basic Form of Turret Tracking
 * 
 * This program applies the rate of change in the position of the target measured by the limelight into the motor;
 * 
 * Using a PID controller would be another way to do this, but using velocities on a 1:1 seems to be more responsive.
 * It should be noted that as of writing this, the added responsiveness has only been measured using input values from the NavX, not the limelight
 */
class LimeLightTracking
    : public frc2::CommandHelper<frc2::CommandBase, LimeLightTracking> {
 public:
  LimeLightTracking(LimeLightSubsystem* camera, TurretSubsystem* turretsys);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
    LimeLightSubsystem* limelight;
    TurretSubsystem* turret;
};
