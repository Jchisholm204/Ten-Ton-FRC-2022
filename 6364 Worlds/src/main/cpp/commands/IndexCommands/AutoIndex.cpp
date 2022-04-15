// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IndexCommands/AutoIndex.hpp"
#include "commands/IndexCommands/Index.hpp"
#include "frc/smartdashboard/SmartDashboard.h"

using namespace IndexCommands;

AutoIndex::AutoIndex(IndexSubsystem* indexSubsystem) : subsystem{indexSubsystem}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subsystem);
  SetName("Auton Indexing");
}

// Called when the command is initially scheduled.
void AutoIndex::Initialize() {
  frc::SmartDashboard::PutString("Indexing", "Auton");
  subsystem->setTop(0);
}

// Called repeatedly when this Command is scheduled to run
void AutoIndex::Execute() {

  // 775 Indexing Powers (CTRE Percent Output)
  double feedPow = 1;
  double backPow = 0.6;


  if ( subsystem->getBotIR() && codex == 1){ codex = 2; };
  if ( subsystem->getFeedPE() && codex == 2 ){ codex = 3; };

  if ( codex == 3 ){
    subsystem->setBottom(0);
    subsystem->setFeed(0);
  }
  else if ( codex == 2 ){
    subsystem->setBottom(0);
    subsystem->setFeed(feedPow);
  }
  else if ( codex == 1 ){
    subsystem->setBottom(backPow);
    subsystem->setFeed(feedPow);
  }
  else{
    printf("Codex OverFlow");
    codex = 1;
  }
}

// Called once the command ends or is interrupted.
void AutoIndex::End(bool interrupted) {
  subsystem->setTop(0);
  subsystem->setBottom(0);
  subsystem->setFeed(0);
  frc::SmartDashboard::PutString("Indexing", "Disabled");
}

// Returns true when the command should end.
bool AutoIndex::IsFinished() {
  return false;
}
