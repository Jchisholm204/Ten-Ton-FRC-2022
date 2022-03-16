// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

// Include Files Needed In ALL Subsystems/Commands
#include <frc2/command/Command.h>
#include "frc/XboxController.h"
#include <frc/PneumaticsControlModule.h>
#include <frc/Compressor.h>
#include <frc/PowerDistribution.h>

// Include Subsystem Files
#include "subsystems/DriveSubsystem.hpp"
#include "subsystems/IndexSubsystem.hpp"
#include "subsystems/IntakeSubsystem.hpp"

#include "commands/OpDriveCommand.hpp"
#include "commands/OpIntakeCommand.hpp"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */

extern frc::XboxController master;
extern frc::XboxController partner;

extern frc::Compressor compressor;

extern frc::PowerDistribution pdp;

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  frc2::Command* GetOpDriveCommand();

  frc2::Command* GetOpIntakeCommand();

  private:
    DriveSubsystem subsystem_drive;
    IndexSubsystem subsystem_index;
    IntakeSubsystem subsystem_intake;

    OpDriveCommand command_opDrive;
    OpIntakeCommand command_opIntake;
};
