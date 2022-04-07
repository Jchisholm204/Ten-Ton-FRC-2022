// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/**
 * @brief Use The LimeLight to Align the DriveBase with a Vision Target
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 */


#pragma once

#include <frc2/command/PIDCommand.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveSubsystem.hpp"
#include "subsystems/LimeLightSubsystem.h"

/**
 * @brief DriveCommands Namespace
 * 
 * Acts as a group for all of the commands that interact with mainly the drivebase
 */
namespace DriveCommands{

/**
 * @brief Use The LimeLight to Align the DriveBase with a Vision Target
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * This Command Returns True When the Robot Has Reached The Setpoint
 * AND is operating below a minimum Velocity (in camera deg)
 * 
 * This Command Ends Instantly If the Limelight Fails To Detect A Target
 * 
 */
  class LimeLightAlign
      : public frc2::CommandHelper<frc2::PIDCommand, LimeLightAlign> {
  public:
    LimeLightAlign(LimeLightSubsystem* limelight, DriveSubsystem* sys_drive, double Tolerance, double target, double endVelocity);

    bool IsFinished() override;

    private:
      bool isFinished;
      DriveSubsystem* drive;
  };
}// End DriveCommands