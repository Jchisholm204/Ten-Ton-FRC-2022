// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "Constants.h"

// Global Variables and Global Objects Go Here (pdp, controllers, pneumatics)
frc::XboxController master(RobotMap::DriverStation::masterController);
frc::XboxController partner(RobotMap::DriverStation::partnerController);

frc::PowerDistribution pdp;

frc::Compressor compressor(frc::PneumaticsModuleType::CTREPCM);

RobotContainer::RobotContainer() : 
command_OpIntake(&subsystem_intake), 
command_OpDrive(&subsystem_drive),
command_OpIndex(&subsystem_index) {
  // Initialize all of your commands and subsystems here

}

frc2::Command* RobotContainer::GetOpIntakeCommand() {
  // An example command will be run in autonomous
  return &command_OpIntake;
}

frc2::Command* RobotContainer::GetOpDriveCommand(){
  return &command_OpDrive;
}

frc2::Command* RobotContainer::GetOpIndexCommand(){
  return &command_OpIndex;
}

/*frc2::Command* RobotContainer::GetOpHangCommand(){
  return &command_OpHang;
}*/