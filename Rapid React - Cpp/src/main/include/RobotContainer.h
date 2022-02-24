// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>

#include "commands/OpIntakeCommand.hpp"
#include "subsystems/IntakeSubsystem.hpp"
#include "subsystems/DriveSubsystem.hpp"
#include "commands/OpDriveCommand.hpp"
#include "subsystems/IndexSubsystem.hpp"
#include "commands/OpIndexCommand.hpp"
//#include "subsystems/HangSubsystem.hpp"
//#include "commands/OpHangCommand.hpp"
#include <frc/XboxController.h>
#include <frc/PowerDistribution.h>
#include <frc/PneumaticsControlModule.h>
#include <frc/Compressor.h>

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetOpIntakeCommand();

  frc2::Command* GetOpDriveCommand();

  frc2::Command* GetOpIndexCommand();

  //frc2::Command* GetOpHangCommand();

 private:
  // The robot's subsystems and commands are defined here...
  // Subsystems
  IntakeSubsystem subsystem_intake;
  IndexSubsystem subsystem_index;
  DriveSubsystem subsystem_drive;
  //HangSubsystem subsystem_hang;

  // Commands
  OpIntakeCommand command_OpIntake;
  OpDriveCommand command_OpDrive;
  OpIndexCommand command_OpIndex;
  //OpHangCommand command_OpHang;

  void ConfigureButtonBindings();
};


/*extern your Global Variables and Objects here so that they can be accessed globally*/
//nomnom 
//intellisense broke no write code noo moreeeee

// Master Controller
extern frc::XboxController master;
// Partner Controller
extern frc::XboxController partner;

// Main Power Distribution Board
//extern frc::PowerDistribution pdp;

// Pneumatics Module Compressor
//extern frc::Compressor compressor;