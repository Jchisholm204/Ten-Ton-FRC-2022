// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Await.h"
#include "tools/Tools.hh"

int starttime = 0;
int delay = 0;

Await::Await(int delayMS) {
  // Use addRequirements() here to declare subsystem dependencies.
  delay = delayMS;
}

// Called when the command is initially scheduled.
void Await::Initialize() {
  starttime = frcTools::Time::Millis();
}

// Called repeatedly when this Command is scheduled to run
void Await::Execute() {}

// Called once the command ends or is interrupted.
void Await::End(bool interrupted) {}

// Returns true when the command should end.
bool Await::IsFinished() {
  return (starttime+delay) < frcTools::Time::Millis();
}
