// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IndexCommands/Index.hpp"
#include "frc/smartdashboard/SmartDashboard.h"

using namespace IndexCommands;

int IndexCommands::codex = 0;

Index::Index(IndexSubsystem* indexSubsystem) : subsystem{indexSubsystem}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subsystem);
}

// Called when the command is initially scheduled.
void Index::Initialize() {
  frc::SmartDashboard::PutBoolean("Indexing Enabled", true);
}

// Called repeatedly when this Command is scheduled to run
void Index::Execute() {
  double iPow = 0.6;
  if ( subsystem->getTopPE() && codex == 0){ codex = 1; };
  if ( subsystem->getBotPE() && codex == 1 ){ codex = 2; };

  if ( codex == 2 ){
    subsystem->setTop(0);
    subsystem->setBottom(0);
    subsystem->setFeed(0);
  }
  else if ( codex == 1 ){
    subsystem->setTop(0);
    subsystem->setBottom(iPow);
    subsystem->setFeed(iPow);
  }
  else if ( codex == 0 ){
    subsystem->setTop(iPow);
    subsystem->setBottom(iPow);
    subsystem->setFeed(iPow);
  }
  else{
    printf("Codex OverFlow");
    codex = 0;
  }
  frc::SmartDashboard::PutNumber("Codex: ", codex);
}

// Called once the command ends or is interrupted.
void Index::End(bool interrupted) {
  subsystem->setTop(0);
  subsystem->setBottom(0);
  subsystem->setFeed(0);
  frc::SmartDashboard::PutBoolean("Indexing Enabled", false);
}

// Returns true when the command should end.
bool Index::IsFinished() {
  return false;
}
