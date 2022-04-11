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
  SetName("Indexing");
}

// Called when the command is initially scheduled.
void Index::Initialize() {
  frc::SmartDashboard::PutString("Indexing", "Enabled");
}

// F500 Indexing Velocity (CTRE Velocity Closed Loop Control)
double vPow = 5000;

// 775 Indexing Power (CTRE Percent Output)
double iPow = 0.6;

// Called repeatedly when this Command is scheduled to run
void Index::Execute() {

  //if ( subsystem->getTopPE() && codex == 0){ codex = 1; };


  // if BallColor == TeamColor && codex == 0 -> Index ball
  if (subsystem->getTeam() == subsystem->getBallColor() && codex == 0){
    codex = 1;
  }

  // If a ball has been registered by the Proximity Sensor, But the Color is undeterminable, set top indexer drive power to zero
  // Fixes Balls getting caught too high in the top indexer
  if(subsystem->getTopIR() && subsystem->getBallColor() == IndexSubsystem::TeamColors::null){
    vPow = 0;
  }
  else{
    vPow = 6000;
  }
  
  if ( subsystem->getBotPE() && codex == 1 ){ codex = 2; };

  if ( codex == 2 ){
    subsystem->setTop(0);
    subsystem->setBottom(0);
    subsystem->setFeed(0);
  }
  else if ( codex == 1 ){
    subsystem->setTop(ControlMode::Velocity, 0);
    subsystem->setBottom(iPow);
    subsystem->setFeed(1);
  }
  else if ( codex == 0 ){
    subsystem->setTopVel(vPow);
    subsystem->setBottom(iPow);
    subsystem->setFeed(1);
  }
  else{
    printf("Codex OverFlow");
    codex = 0;
  }
}

// Called once the command ends or is interrupted.
void Index::End(bool interrupted) {
  subsystem->setTop(0);
  subsystem->setBottom(0);
  subsystem->setFeed(0);
  frc::SmartDashboard::PutString("Indexing", "Disabled");
}

// Returns true when the command should end.
bool Index::IsFinished() {
  return false;
}
