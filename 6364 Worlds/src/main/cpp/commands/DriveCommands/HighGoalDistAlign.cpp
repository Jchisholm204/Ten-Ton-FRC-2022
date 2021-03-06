// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/**
 * @brief High Goal Distance Alignment Command : Move the Robot to the correct distance from the goal to shoot high
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * Can be invoked during operator control or used in parallel race group -> does not return finished
 * 
 * Uses Drive Ultrasonics Mounted on the front of the robot to distance the robot from the goal
 * 
 */

#include "commands/DriveCommands/HighGoalDistAlign.hpp"
#include "Constants.h"

using namespace DriveCommands;

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
HighGoalDistAlign::HighGoalDistAlign(DriveSubsystem* drive)
    : CommandHelper(
          frc2::PIDController(20, 0, 160),
          // This should return the measurement
          [drive] { return drive->getUltrasonic(); },
          // This should return the setpoint (can also be a constant)
          [] { return kDrive::ultrasonicTV; },
          // This uses the output
          [drive](double output) {
            // Use the output here
            output = output*1500;
            if(output > 10500) {output = 10500;};
            if(output < -10500) {output = -10500;};
            drive->set(-output);
          }) {}

// Returns true when the command should end.
bool HighGoalDistAlign::IsFinished() {
  return false;
}
