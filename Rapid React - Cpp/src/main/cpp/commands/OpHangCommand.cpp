// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/OpHangCommand.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "ctre/Phoenix.h"

OpHangCommand::OpHangCommand(HangSubsystem* Subsystem_hang) : hang{Subsystem_hang} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(hang);
}

// Called when the command is initially scheduled.
void OpHangCommand::Initialize() {
  frc::SmartDashboard::PutNumber("Winch Target: ", hang->getWinch());
  frc::SmartDashboard::PutNumber("Winch Cur Pos: ", hang->getWinch());
  frc::SmartDashboard::PutNumber("Claw Target: ", hang->getClaw());
  frc::SmartDashboard::PutNumber("Claw Cur Pos: ", hang->getClaw());
}

// Called repeatedly when this Command is scheduled to run
void OpHangCommand::Execute() {
  double targPos = frc::SmartDashboard::GetNumber("Winch Target: ", hang->getWinch());
  frc::SmartDashboard::PutNumber("Winch Cur Pos: ", hang->getWinch());
  hang->setWinch(ControlMode::MotionMagic, targPos);

  frc::SmartDashboard::PutNumber("Winch Current Draw: ", hang->getWinchDraw());

  double targPosC = frc::SmartDashboard::GetNumber("Winch Target: ", hang->getClaw());
  frc::SmartDashboard::PutNumber("Winch Cur Pos: ", hang->getClaw());
  hang->setClaw(ControlMode::MotionMagic, targPosC);
}

// Called once the command ends or is interrupted.
void OpHangCommand::End(bool interrupted) {
  hang->setWinch(ControlMode::Position, hang->getWinch());
}

// Returns true when the command should end.
bool OpHangCommand::IsFinished() {
  return false;
}
