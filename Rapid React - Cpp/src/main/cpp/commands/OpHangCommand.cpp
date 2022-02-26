// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/OpHangCommand.hpp"
#include <frc/smartdashboard/SmartDashboard.h>
#include "ctre/Phoenix.h"
#include "RobotContainer.h"
#include "Constants.h"

//SmartDashboard
std::string_view SDwmv = "Winch iMax Velocity: ";
std::string_view SDwp = "Winch Cur Pos: ";
std::string_view SDcmv = "Claw iMax Velocity: ";
std::string_view SDcp = "Claw Cur Pos: ";

OpHangCommand::OpHangCommand(HangSubsystem* Subsystem_hang) : hang{Subsystem_hang} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(Subsystem_hang);
}

// Called when the command is initially scheduled.
void OpHangCommand::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void OpHangCommand::Execute() {

  frc::SmartDashboard::PutNumber("Winch Current Draw: ", hang->getWinchDraw());
  frc::SmartDashboard::PutNumber("Winch RPM: ", hang->getWinchRPM());
  frc::SmartDashboard::PutNumber("Claw RPM: ", hang->getClawRPM());

  if(partner.GetYButton()){
    hang->setClaw(ControlMode::Velocity, 1000);
    frc::SmartDashboard::PutBoolean("on", true);
  }
  else if(partner.GetAButton()){
    hang->setClaw(ControlMode::Velocity, -1000);
    frc::SmartDashboard::PutBoolean("on", true);
  }
  else{
    hang->setClaw(ControlMode::Velocity, 0);
    frc::SmartDashboard::PutBoolean("on", false);
  }

  if(partner.GetXButton()){
    hang->setWinch(ControlMode::Velocity, 22000);
    frc::SmartDashboard::PutBoolean("Won", true);
  }
  else if(partner.GetBButton()){
    hang->setWinch(ControlMode::Velocity, -22000);
    frc::SmartDashboard::PutBoolean("Won", true);
  }
  else{
    hang->setWinch(ControlMode::Velocity, 0);
    frc::SmartDashboard::PutBoolean("Won", false);
  }

  if(partner.GetRightBumperPressed()){
    bool p = hang->GetPressure();
    hang->ApplyPressure(!p);
  }

}

// Called once the command ends or is interrupted.
void OpHangCommand::End(bool interrupted) {
  hang->setWinch(ControlMode::PercentOutput, 0);
  hang->setClaw(ControlMode::PercentOutput, 0);
}

// Returns true when the command should end.
bool OpHangCommand::IsFinished() {
  return false;
}
