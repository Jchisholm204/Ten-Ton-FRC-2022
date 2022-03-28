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
 * 
 *  Copyright (c) FIRST and other WPILib contributors.
 *  Open Source Software; you can modify and/or share it under the terms of
 *  the WPILib BSD license file in the root directory of this project.
 */

#include "RobotContainer.h"
#include "Constants.h"
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc/Joystick.h>

frc::XboxController master(RobotMap::DriverStation::masterController);
frc::XboxController partner(RobotMap::DriverStation::partnerController);
frc::Joystick joystick(2);

frc::Compressor compressor(frc::PneumaticsModuleType::CTREPCM);
frc::PowerDistribution pdp{0, frc::PowerDistribution::ModuleType::kCTRE};

/**
 * @brief Construct a new Robot Container:: Robot Container object
 * 
 * Inside RobotContainer is where Subsystems should be assigned default commands.
 * 
 * Default commands run whenever the subsystem is not currently being accessed by another command.
 * 
 * Appropriate uses for this would be to assign the operator drive command to the drive subsystem.
 * This way, whenever nothing else is using the drive subsystem (auto, alignment program) the driver
 * will have control of the base's motion.
 * 
 * More information about the RobotContainer and Commands can be found at:
 * https://docs.wpilib.org/en/stable/docs/software/commandbased/commands.html
 * 
 */

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  ConfigureButtonBindings();

  // Set Default Commands for Subsystems
  subsystem_index.SetDefaultCommand(IndexCommands::Index(&subsystem_index));
  subsystem_drive.SetDefaultCommand(DriveCommands::OpDrive(&subsystem_drive));
  subsystem_intake.SetDefaultCommand(IntakeCommands::OpIntake(&subsystem_intake));
  subsystem_winch.SetDefaultCommand(HangCommands::PneumaticControl(&subsystem_winch));
}

/**
 * @brief Configure Button Bindings
 * 
 * Used to Configure any buttons on the controller that could be used to interupt commands.
 * 
 * IE; the shoot command that interrupts the indexing command, or the alignment command that
 * interrupts the operator drive command.
 * 
 */

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

   // Shoot Balls Stored within the index when Right Bumper is Pressed
  frc2::JoystickButton(&joystick, 1)
    .WhenPressed(new IndexCommands::ShootLow(&subsystem_index));

 // Shoot Balls Stored within the index when Right Bumper is Pressed
  frc2::JoystickButton(&master, frc::XboxController::Button::kRightBumper)
    .WhenPressed(new IndexCommands::ShootLow(&subsystem_index));

  // Shoot High Goal - > first lower balls, then speed up top indexer and shoot from feed and bottom
  frc2::JoystickButton(&master, frc::XboxController::Button::kA)
    .WhenPressed(new IndexCommands::BackFeed(&subsystem_index)
    );
  frc2::JoystickButton(&master, frc::XboxController::Button::kLeftBumper)
    .WhenPressed(new IndexCommands::ShootHigh(&subsystem_index)
    );

 // Shoot Balls Stored within the index when Right Bumper is Pressed
 frc2::JoystickButton(&partner, frc::XboxController::Button::kRightBumper)
    .WhenPressed(new IndexCommands::ShootLow(&subsystem_index));
/*
  frc2::JoystickButton(&partner, frc::XboxController::Button::kLeftBumper)
    .WhenPressed(new frc2::SequentialCommandGroup{
      IndexCommands::BackFeed(&subsystem_index),
      IndexCommands::ShootHigh(&subsystem_index)
    });
*/
  frc2::JoystickButton(&partner, frc::XboxController::Button::kA) && frc2::Button([this]{return !subsystem_winch.getLowerLimit();})
    .WhenHeld(new HangCommands::WinchCommands::WinchDown(&subsystem_winch));

  frc2::JoystickButton(&partner, frc::XboxController::Button::kY)
    .WhenHeld(new HangCommands::WinchCommands::LowerRobot(&subsystem_winch));

  frc2::JoystickButton(&partner, frc::XboxController::Button::kX)
    .WhenHeld(new HangCommands::ClawCommands::ClawUp(&subsystem_claw));

  frc2::JoystickButton(&partner, frc::XboxController::Button::kB)
    .WhenHeld(HangCommands::ClawCommands::ClawDown(&subsystem_claw));

  // Index Toggle Command - Allow Partner controller to stop indexing
  frc2::JoystickButton(&partner, frc::XboxController::Button::kLeftBumper)
    .ToggleWhenPressed(IndexCommands::Manual(&subsystem_index));
}

// This Command Returns the Default Autonomous Command
frc2::Command* RobotContainer::GetAutonomousCommand() {
  return &simpleAuto;
}