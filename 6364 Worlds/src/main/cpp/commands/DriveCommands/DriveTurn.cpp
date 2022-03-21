// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveCommands/DriveTurn.hpp"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
DriveCommands::DriveTurn::DriveTurn(DriveSubsystem* sys_drive, double target)
    : CommandHelper(
          frc2::PIDController(1, 0, 10),
          // This should return the measurement
          [sys_drive] { return sys_drive->getRotation(); },
          // This should return the setpoint (can also be a constant)
          target,
          // This uses the output
          [sys_drive](double output) {
            sys_drive->set(ControlMode::PercentOutput, output, -output);
          }), isFinished{false} {
            AddRequirements(sys_drive);
            sys_drive->resetNav();
            m_controller.SetTolerance(3);
            
          }

// Returns true when the command should end.
bool DriveCommands::DriveTurn::IsFinished() {
  return GetController().AtSetpoint();
}
