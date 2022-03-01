// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "Constants.h"

// Global Variables and Global Objects Go Here (pdp, controllers, pneumatics)
frc::XboxController master(RobotMap::DriverStation::masterController);
frc::XboxController partner(RobotMap::DriverStation::partnerController);

frc::SendableChooser<int> recording_chooser;
frc::SendableChooser<int> SelectedAuto;

/**
 * NOTE:
 * Setting the Module Type stops the robot from failing to run the code,
 * However, it is still unknown as to if this will actually report correct values,
 * or even report any values at all
 */
frc::PowerDistribution pdp(0, frc::PowerDistribution::ModuleType::kCTRE); //BROKEN (possibly)

frc::Compressor compressor(frc::PneumaticsModuleType::CTREPCM);

RobotContainer::RobotContainer() : 
command_OpIntake(&subsystem_intake), 
command_OpDrive(&subsystem_drive),
command_OpIndex(&subsystem_index),
command_OpHang(&subsystem_hang),
command_auto_run(&subsystem_drive, &subsystem_index, &subsystem_intake),
command_auto_record(&subsystem_drive, &subsystem_index, &subsystem_intake) {
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

frc2::Command* RobotContainer::GetOpHangCommand(){
  return &command_OpHang;
}

frc2::Command* RobotContainer::GetRecordCommand(){
  return &command_auto_record;
}

frc2::Command* RobotContainer::GetAutoCommand(){
  return &command_auto_run;
}