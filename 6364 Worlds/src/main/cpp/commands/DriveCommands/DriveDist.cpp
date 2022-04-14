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
#include "tools/Tools.hh"

DriveCommands::DriveDist::DriveDist(DriveSubsystem* DriveSubsystem, double distance, double timeout, bool reset) : drive{DriveSubsystem}, resetEnc{reset}, driveDist{distance}, timeout{timeout}{
  AddRequirements(drive);
  SetName("Drive Distance");

  double dInches = distance;

  // DriveBase Wheel Radius
  double WheelRadius = 3.125; // inches
  // Motor rotations required for one wheel rotation
  double gearBoxRatio = 18; //18 rotations of the motor for one rotation of the wheel

  // Calculate the Circumference of the wheel given its Radius
  double WheelCircumference = 2 * 3.14159265358979323846 /*pi*/ * WheelRadius;

  // Inches / Circumference gives us the number of rotations the wheel has to make
  double rotations = dInches/WheelCircumference;

  // Convert wheel rotations to Encoder Units by multiplying it by 2408 (one full rotation in encoder units)
  // And Scale it according to the Gear Box Ratio
  driveDist = rotations * 2408 * gearBoxRatio;

  //distance = (dInches * (2408 * gearBoxRatio)) / WheelCircumference;

}

// Called when the command is initially scheduled.
void DriveCommands::DriveDist::Initialize() {
  if (resetEnc){
    drive->resetDrive();
  }
  drive->set(ControlMode::MotionMagic, driveDist);
  cmdFinished = false;
  startTime = frcTools::Time::Millis();
}

// Called repeatedly when this Command is scheduled to run
void DriveCommands::DriveDist::Execute() {
  if(startTime + timeout < frcTools::Time::Millis()){
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
