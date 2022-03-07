// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/IndexSubsystem.hpp"
#include "subsystems/DriveSubsystem.hpp"
#include "subsystems/IntakeSubsystem.hpp"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class SimpleAuto
    : public frc2::CommandHelper<frc2::CommandBase, SimpleAuto> {
 public:
  SimpleAuto(IndexSubsystem *indx, DriveSubsystem *drve, IntakeSubsystem *intke);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
    IndexSubsystem* index;
    DriveSubsystem* drive;
    IntakeSubsystem* intake;
};
