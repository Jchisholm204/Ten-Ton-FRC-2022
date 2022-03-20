// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/**
 * @brief Drive Distance : Move the Robot forwards or Backwards in a line
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * Drive Distance can be invoked whenever linear motion needs to occur
 * 
 * Drive distance uses the CTRE Closed Loop Magic Motion and math to convert inches into encoder units, and then move
 * 
 * Distance is turned from Inches into encoder units by first converting the wheel radius into circumference,
 * then invoking the drive gearbox ratio into the equation in order to determine motor rotations per inch.
 * This value is finally multipled by 2408, the encoder count for one full rotation of a Falcon500 Motor,
 * then the by the number of inches you would like to drive.
 * 
 * Positive Inches moves the Drivebase forward, while a negative value will move the drivebase in reverse
 * 
 */

#include "commands/DriveCommands/DriveDist.hpp"

DriveCommands::DriveDist::DriveDist(DriveSubsystem* DriveSubsystem, double distance, double error, bool reset) : drive{DriveSubsystem}, resetEnc{reset}, driveDist{distance}, dError{error}, cmdFinished{false}{
  AddRequirements(drive);

  double dInches = distance;
  double WheelRadius = 4.8; // inches
  double gearBoxRatio = 18; //18 rotations of the motor for one rotation of the wheel

  double WheelCircumference = 2 * 3.14159265358979323846 /*pi*/ * WheelRadius;

  distance = (dInches * (2408 * gearBoxRatio)) / WheelCircumference;

}

// Called when the command is initially scheduled.
void DriveCommands::DriveDist::Initialize() {
  if (resetEnc){
    drive->resetDrive();
  }
  drive->set(ControlMode::MotionMagic, driveDist);
}

// Called repeatedly when this Command is scheduled to run
void DriveCommands::DriveDist::Execute() {
  if(drive->getPos() > (driveDist*(1-dError)) && drive->getPos() < (driveDist*(1+dError)))
  {
    cmdFinished = true;
  }
}

// Called once the command ends or is interrupted.
void DriveCommands::DriveDist::End(bool interrupted) {
}

// Returns true when the command should end.
bool DriveCommands::DriveDist::IsFinished() {
  return cmdFinished;
}
