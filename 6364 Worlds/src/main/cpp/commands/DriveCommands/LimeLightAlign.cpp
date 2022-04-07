// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveCommands/LimeLightAlign.hpp"

DriveCommands::LimeLightAlign::LimeLightAlign(LimeLightSubsystem* limelight, DriveSubsystem* sys_drive, double Tolerance, double target, double endVelocity)
    : CommandHelper(
          frc2::PIDController(10, 0, 50),
          // This should return the measurement
          [limelight] { return limelight->getX(); },
          // This should return the setpoint (can also be a constant)
          target,
          // This uses the output
          [sys_drive](double output) {
            sys_drive->set(ControlMode::PercentOutput, output, -output);
          }), isFinished{!limelight->hasTarget()}, drive{sys_drive} {
            AddRequirements(sys_drive);
            AddRequirements(limelight);
            m_controller.DisableContinuousInput();
            m_controller.SetTolerance(Tolerance, endVelocity);
            
          }

// Returns true when the command should end.
bool DriveCommands::LimeLightAlign::IsFinished() {
  drive->set(0);
  return GetController().AtSetpoint() || isFinished;
}