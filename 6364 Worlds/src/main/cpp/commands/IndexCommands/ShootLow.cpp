// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IndexCommands/ShootLow.hpp"
#include "commands/IndexCommands/Index.hpp"
#include <frc/Timer.h>
#include <tools/Tools.hh>

using namespace IndexCommands;

ShootLow::ShootLow(IndexSubsystem* indexSubsystem) : subsystem{indexSubsystem}, isFinished{false}, startTime{frcTools::Time::Millis()}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(indexSubsystem);
}

// Called when the command is initially scheduled.
void ShootLow::Initialize() {
  startTime = frcTools::Time::Millis();
  isFinished = false;

  subsystem->setFeed(0);
  subsystem->setTopVel(TopIndexConverter(fxMaxRPM*0.5));
  subsystem->setBottom(1);
  IndexCommands::codex = 0;
}

// Called repeatedly when this Command is scheduled to run
void ShootLow::Execute() {
  if(frcTools::Time::Millis() > startTime + 1500){
    isFinished = true;
  }
}

// Called once the command ends or is interrupted.
void ShootLow::End(bool interrupted) {
  IndexCommands::codex = 0;
}

// Returns true when the command should end.
bool ShootLow::IsFinished() {
  return isFinished;
}
