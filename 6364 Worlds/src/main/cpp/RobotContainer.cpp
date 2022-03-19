// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "Constants.h"
#include <frc2/command/button/JoystickButton.h>

frc::XboxController master(RobotMap::DriverStation::masterController);
frc::XboxController partner(RobotMap::DriverStation::partnerController);

frc::Compressor compressor(frc::PneumaticsModuleType::CTREPCM);
frc::PowerDistribution pdp{0, frc::PowerDistribution::ModuleType::kCTRE};

RobotContainer::RobotContainer() :
command_opDrive{&subsystem_drive},
command_opIntake{&subsystem_intake}{
  // Initialize all of your commands and subsystems here
  ConfigureButtonBindings();
   subsystem_index.SetDefaultCommand(IndexCommands::Index(&subsystem_index));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings hereW
/*
  // Grab the hatch when the 'A' button is pressed.
  frc2::JoystickButton(&master, frc::XboxController::Button::kRightBumper)
      .WhenPressed(new GrabHatch(&m_hatch));
  // Release the hatch when the 'B' button is pressed.
  frc2::JoystickButton(&m_driverController, frc::XboxController::Button::kB)
      .WhenPressed(new ReleaseHatch(&m_hatch));
  // While holding the shoulder button, drive at half speed
  frc2::JoystickButton(&m_driverController,
                       frc::XboxController::Button::kRightBumper)
      .WhenHeld(new HalveDriveSpeed(&m_drive));
  */

 // Shoot Balls Stored within the index when Right Bumper is Pressed
 frc2::JoystickButton(&master, frc::XboxController::Button::kRightBumper)
    .WhenPressed(new IndexCommands::ShootLow(&subsystem_index));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // This Command Returns the Default Autonomous Command
  return nullptr;
}

frc2::Command* RobotContainer::GetOpDriveCommand(){
  return &command_opDrive;
}

frc2::Command* RobotContainer::GetOpIntakeCommand(){
  return &command_opIntake;
}