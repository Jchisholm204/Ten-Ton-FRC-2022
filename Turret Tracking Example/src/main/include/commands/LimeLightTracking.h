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
    float error = {0};
    float error_prior = {0};
    float integral = {0};
    float integral_prior = {0};
    float derivitive = {0};
    float output = {0};

};
