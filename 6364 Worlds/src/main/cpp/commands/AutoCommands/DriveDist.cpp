// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoCommands/DriveDist.hpp"

AutoCommands::DriveDist::DriveDist(DriveSubsystem* DriveSubsystem, double distance, double error, bool reset) : drive{DriveSubsystem}, resetEnc{reset}, driveDist{distance}, dError{error}, cmdFinished{false}{
  AddRequirements(drive);
}

// Called when the command is initially scheduled.
void AutoCommands::DriveDist::Initialize() {
  if (resetEnc){
    drive->resetDrive();
  }
  drive->set(ControlMode::MotionMagic, driveDist);
}

// Called repeatedly when this Command is scheduled to run
void AutoCommands::DriveDist::Execute() {
  if(drive->getPos() > (driveDist*(1-dError)) && drive->getPos() < (driveDist*(1+dError)))
  {
    cmdFinished = true;
  }
}

// Called once the command ends or is interrupted.
void AutoCommands::DriveDist::End(bool interrupted) {
}

// Returns true when the command should end.
bool AutoCommands::DriveDist::IsFinished() {
  return cmdFinished;
}
