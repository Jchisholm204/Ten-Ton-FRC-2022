// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "Constants.h"

frc::XboxController master(RobotMap::DriverStation::masterController);
frc::XboxController partner(RobotMap::DriverStation::partnerController);

frc::Compressor compressor(frc::PneumaticsModuleType::CTREPCM);
frc::PowerDistribution pdp{0, frc::PowerDistribution::ModuleType::kCTRE};

RobotContainer::RobotContainer() :
command_opDrive{&subsystem_drive},
command_opIntake{&subsystem_intake}{
  // Initialize all of your commands and subsystems here
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