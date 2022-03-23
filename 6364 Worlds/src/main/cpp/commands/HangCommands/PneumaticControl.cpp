// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/HangCommands/PneumaticControl.hpp"
#include "RobotContainer.h"

HangCommands::PneumaticControl::PneumaticControl(WinchSubsystem* sys_winch) : winch{sys_winch}{
  AddRequirements(winch);
}

// Called when the command is initially scheduled.
void HangCommands::PneumaticControl::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void HangCommands::PneumaticControl::Execute() {

  if(partner.GetPOV(0) == 0){
    winch->setSolenoid(true);
  }

  if(partner.GetPOV(0) == 180){
    winch->setSolenoid(false);
  }

}

// Called once the command ends or is interrupted.
void HangCommands::PneumaticControl::End(bool interrupted) {}

// Returns true when the command should end.
bool HangCommands::PneumaticControl::IsFinished() {
  return false;
}
