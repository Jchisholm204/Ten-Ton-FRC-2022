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

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>
#include "subsystems/DriveSubsystem.hpp"

/**
 * @brief DriveCommands Namespace
 * 
 * Acts as a group for all of the commands that interact with mainly the drivebase
 */
namespace DriveCommands{

  /**
   * @brief Drive Commands -> High Goal Distance Align
   * Extends PID Command
   * 
   */
  class HighGoalDistAlign
      : public frc2::CommandHelper<frc2::PIDCommand, HighGoalDistAlign> {
  public:
    HighGoalDistAlign(DriveSubsystem* drive);

    bool IsFinished() override;

    private:
      bool isFinished;
      DriveSubsystem* drivef;
  };
}