// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/button/JoystickButton.h>

#include "commands/DefaultDrive.h"
#include "commands/GrabHatch.h"
#include "commands/HalveDriveSpeed.h"
#include "commands/ReleaseHatch.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Add commands to the autonomous command chooser
  m_chooser.SetDefaultOption("Simple Auto", &m_simpleAuto);
  m_chooser.AddOption("Complex Auto", &m_complexAuto);

  // Put the chooser on the dashboard
  frc::Shuffleboard::GetTab("Autonomous").Add(m_chooser);

  // Configure the button bindings
  ConfigureButtonBindings();

  // Set up default drive command
  m_drive.SetDefaultCommand(DefaultDrive(
      &m_drive, [this] { return -m_driverController.GetLeftY(); },
      [this] { return m_driverController.GetRightX(); }));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  // NOTE: Using `new` here will leak these commands if they are ever no longer
  // needed. This is usually a non-issue as button-bindings tend to be permanent
  // - however, if you wish to avoid this, the commands should be
  // stack-allocated and declared as members of RobotContainer.

  // Grab the hatch when the 'A' button is pressed.
  frc2::JoystickButton(&m_driverController, frc::XboxController::Button::kA)
      .WhenPressed(new GrabHatch(&m_hatch));
  // Release the hatch when the 'B' button is pressed.
  frc2::JoystickButton(&m_driverController, frc::XboxController::Button::kB)
      .WhenPressed(new ReleaseHatch(&m_hatch));
  // While holding the shoulder button, drive at half speed
  frc2::JoystickButton(&m_driverController,
                       frc::XboxController::Button::kRightBumper)
      .WhenHeld(new HalveDriveSpeed(&m_drive));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // Runs the chosen command in autonomous
  return m_chooser.GetSelected();
}
