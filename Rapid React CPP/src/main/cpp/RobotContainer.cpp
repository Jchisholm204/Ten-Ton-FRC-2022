// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <frc/XboxController.h>

frc::XboxController master(0);
frc::XboxController partner(0);

RobotContainer::RobotContainer() : OPIndex(&index) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  
}

frc2::Command* RobotContainer::getOPIndex() {
  // An example command will be run in autonomous
  return &OPIndex;
}
