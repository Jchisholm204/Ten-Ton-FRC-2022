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

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveSubsystem.hpp"

/**
 * @brief DriveCommands Namespace
 * 
 * Acts as a group for all of the commands that interact with mainly the drivebase
 */
namespace DriveCommands{

  class DriveDist
    : public frc2::CommandHelper<frc2::CommandBase, DriveDist> {
  public:

    /**
     * Auton Commands -> Drive Distance
     * 
     * @param DriveSubsystem Pass for the Robots DriveSubsystem
     * @param distance The Distance to drive (in inches) 
     * @param error Percent error [0,1] : Best between 0.1 and 0.05
     * @param reset TRUE to reset the drivebase encoders
     * @returns TRUE when drivebase encoder read within Error
     */
    DriveDist(DriveSubsystem* DriveSubsystem, double distance, double error, bool reset);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

  private:
    DriveSubsystem* drive;
    bool resetEnc;
    double driveDist;
    double dError;
    bool cmdFinished;
};
  
} // namespace DriveCommands
