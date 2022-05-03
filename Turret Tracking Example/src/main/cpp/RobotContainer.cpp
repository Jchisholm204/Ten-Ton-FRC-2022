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

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}