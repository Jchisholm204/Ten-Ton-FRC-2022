// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveSubsystem.hpp"

namespace AutoCommands{
  class DriveDist
    : public frc2::CommandHelper<frc2::CommandBase, DriveDist> {
  public:

    /**
     * Auton Commands -> Drive Distance
     * 
     * @param DriveSubsystem Pass for the Robots DriveSubsystem
     * @param distance The Distance to drive (in inches) (!INCHES NOT DONE YET) TODO: Inches 
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
  
} // namespace AutoCommands
