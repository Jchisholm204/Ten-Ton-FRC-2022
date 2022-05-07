// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"


RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  subsystem_turret.SetDefaultCommand(LimeLightTracking(&subsystem_limelight, &subsystem_turret));

}

frc::XboxController master(0);

void RobotContainer::ConfigureButtonBindings() {

  // Shoot using master controller Right Bumper
  (frc2::JoystickButton(&master, frc::XboxController::Button::kRightBumper) && frc2::Button([this] {return subsystem_shooter.TargetLock();}))
  .WhenActive(new frc2::RunCommand(
    [this] {
      subsystem_shooter.setFeed(1);
    },
    {&subsystem_shooter}));

  // When Trying to shoot but LimeLight Not lined up, Buzz Controller
  (frc2::JoystickButton(&master, frc::XboxController::Button::kRightBumper) && frc2::Button([this] {return !subsystem_shooter.TargetLock();}))
  .WhenActive(new frc2::InstantCommand(
    [this] {
      master.SetRumble(frc::XboxController::RumbleType::kRightRumble, 1);
    }))
  .WhenInactive(new frc2::InstantCommand(
    [this] {
      master.SetRumble(frc::XboxController::RumbleType::kRightRumble, 0);
    }));

  // Spin Up FW and Backspin Motors
  frc2::JoystickButton(&master, frc::XboxController::Button::kA)
  .WhenPressed(new frc2::InstantCommand([this]{
    subsystem_shooter.setFlyWheel(ControlMode::PercentOutput, 1);
    subsystem_shooter.setBackSpin(ControlMode::PercentOutput, 1);
    }, {&subsystem_shooter}));
}