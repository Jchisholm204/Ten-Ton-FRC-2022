// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/**
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * RobotContainer
 * 
 * The RobotContainer is where the bulk of the button mappings and declarations are.
 * 
 * Most Declarations are kept within subsystems and the RobotContainer, However many devices
 * such as the PDP, PCM Compressor, and controllers are declared publicly without a class to
 * ensure that they can be globally accessed
 * 
 */

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

// Include Commands
#include "commands/DriveCommands/OpDrive.hpp"

#include "commands/IntakeCommands/OpIntake.hpp"

#include "commands/IndexCommands/Index.hpp"
#include "commands/IndexCommands/ShootLow.hpp"
#include "commands/IndexCommands/BackFeed.hpp"
#include "commands/IndexCommands/ShootHigh.hpp"

#include "commands/AutonCommand.hpp"

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

  void ConfigureButtonBindings();

  frc2::Command* GetAutonomousCommand();

  private:
    // Declare Subsystems as part of RobotContainer

    DriveSubsystem subsystem_drive;
    IndexSubsystem subsystem_index;
    IntakeSubsystem subsystem_intake;

    // Declare our Auto as part of RobotContainer
    AutonCommand simpleAuto{&subsystem_drive, &subsystem_intake, &subsystem_index};
};
