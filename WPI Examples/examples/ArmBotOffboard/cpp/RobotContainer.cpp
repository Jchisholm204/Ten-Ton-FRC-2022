// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/button/JoystickButton.h>
#include <units/angle.h>

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  // Set up default drive command
  m_drive.SetDefaultCommand(frc2::RunCommand(
      [this] {
        m_drive.ArcadeDrive(-m_driverController.GetLeftY(),
                            m_driverController.GetRightX());
      },
      {&m_drive}));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  // Move the arm to 2 radians above horizontal when the 'A' button is pressed.
  frc2::JoystickButton(&m_driverController, frc::XboxController::Button::kA)
      .WhenPressed([this] { m_arm.SetGoal(2_rad); }, {&m_arm});

  // Move the arm to neutral position when the 'B' button is pressed.
  frc2::JoystickButton(&m_driverController, frc::XboxController::Button::kB)
      .WhenPressed([this] { m_arm.SetGoal(ArmConstants::kArmOffset); },
                   {&m_arm});

  // While holding the shoulder button, drive at half speed
  frc2::JoystickButton(&m_driverController,
                       frc::XboxController::Button::kRightBumper)
      .WhenPressed([this] { m_drive.SetMaxOutput(0.5); })
      .WhenReleased([this] { m_drive.SetMaxOutput(1); });
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // Runs the chosen command in autonomous
  return new frc2::InstantCommand([] {});
}
