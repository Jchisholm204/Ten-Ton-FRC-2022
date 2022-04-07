// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>

#include "subsystems/DriveSubsystem.hpp"

/**
 * @brief DriveCommands Namespace
 * 
 * Acts as a group for all of the commands that interact with mainly the drivebase
 */
namespace DriveCommands{

  class DriveTurn
      : public frc2::CommandHelper<frc2::PIDCommand, DriveTurn> {
    public:
      DriveTurn(DriveSubsystem* sys_drive, double target);

      bool IsFinished() override;

    private:
      bool isFinished;
  };
}