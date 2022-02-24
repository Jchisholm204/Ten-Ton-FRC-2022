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
  AddRequirements(hang);
}

double Wpos;
double Cpos;

// Called when the command is initially scheduled.
void OpHangCommand::Initialize() {
  frc::SmartDashboard::PutNumber(SDwmv, c_TalonUPR(600));
  frc::SmartDashboard::PutNumber(SDwp, hang->getWinch());
  frc::SmartDashboard::PutNumber(SDcmv, c_TalonUPR(600));
  frc::SmartDashboard::PutNumber(SDcp, hang->getClaw());

  Wpos = hang->getWinch();
  Cpos = hang->getClaw();
}

// Called repeatedly when this Command is scheduled to run
void OpHangCommand::Execute() {

  double Wmv = frc::SmartDashboard::GetNumber(SDwmv, c_TalonUPR(600));
  frc::SmartDashboard::PutNumber(SDwp, hang->getWinch());
  

  frc::SmartDashboard::PutNumber("Winch Current Draw: ", hang->getWinchDraw());
  frc::SmartDashboard::PutNumber("Winch RPM: ", hang->getWinchRPM());
  frc::SmartDashboard::PutNumber("Claw RPM: ", hang->getClawRPM());

  double Cmv = frc::SmartDashboard::GetNumber(SDcmv, c_TalonUPR(600));
  frc::SmartDashboard::PutNumber(SDcp, hang->getClaw());

  if(partner.GetYButton()){
    hang->setWinch(ControlMode::Velocity, c_TalonUPR(Wmv));
  }
  else if(partner.GetAButton()){
    hang->setWinch(ControlMode::Velocity, -c_TalonUPR(Wmv));
  }
  else{
    hang->setWinch(ControlMode::Position, Wpos);
  }

  if(partner.GetYButtonReleased() || partner.GetAButtonReleased()){
    Wpos = hang->getWinch();
  }

  if(partner.GetXButton()){
    hang->setWinch(ControlMode::Velocity, c_TalonUPR(Cmv));
  }
  else if(partner.GetBButton()){
    hang->setWinch(ControlMode::Velocity, -c_TalonUPR(Cmv));
  }
  else{
    hang->setWinch(ControlMode::Position, Cpos);
  }

  if(partner.GetXButtonReleased() || partner.GetBButtonReleased()){
    Cpos = hang->getClaw();
  }


}

// Called once the command ends or is interrupted.
void OpHangCommand::End(bool interrupted) {
  hang->setWinch(ControlMode::Position, hang->getWinch());
  hang->setClaw(ControlMode::Position, hang->getClaw());
}

// Returns true when the command should end.
bool OpHangCommand::IsFinished() {
  return false;
}
