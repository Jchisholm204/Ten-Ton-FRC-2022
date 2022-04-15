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
#include <frc/smartdashboard/SendableChooser.h>

// Include Subsystem Files
#include "subsystems/DriveSubsystem.hpp"
#include "subsystems/IndexSubsystem.hpp"
#include "subsystems/IntakeSubsystem.hpp"
#include "subsystems/WinchSubsystem.hpp"
#include "subsystems/ClawSubsystem.hpp"
#include "subsystems/LimeLightSubsystem.h"

// Include Commands
#include "commands/Commands.inc"

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

// Set the Robots Team Color for Color Sorting Through sDash
extern frc::SendableChooser<IndexSubsystem::TeamColors> teamColor;

class RobotContainer {
 public:
  RobotContainer();

  void ConfigureMasterBindings();

  void ConfigurePartnerBindings();

  void ConfigureJoystickBindings();

  frc2::Command* GetAutonomousCommand();



  private:
    // Declare Subsystems as part of RobotContainer

    DriveSubsystem subsystem_drive;
    IndexSubsystem subsystem_index;
    IntakeSubsystem subsystem_intake;
    WinchSubsystem subsystem_winch;
    ClawSubsystem subsystem_claw;
    LimeLightSubsystem subsystem_limelight;

    // Declare our Auto as part of RobotContainer
    AutonCommand simpleAuto{&subsystem_drive, &subsystem_intake, &subsystem_index, &subsystem_limelight};
};
