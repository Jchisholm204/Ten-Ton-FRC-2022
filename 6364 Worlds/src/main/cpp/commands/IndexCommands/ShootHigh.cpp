// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IndexCommands/ShootHigh.hpp"
#include "Constants.h"
#include "tools/Tools.hh"

IndexCommands::ShootHigh::ShootHigh(IndexSubsystem* sys_index) : index{sys_index}, isFinished{false}, reachedRPM{false} {
  AddRequirements(index);
}

// Called when the command is initially scheduled.
void IndexCommands::ShootHigh::Initialize() {
  index->setFeed(0);
  index->setBottom(0);
  index->setTopVel(c_TalonUPR(6000));

  startTime = frcTools::Time::Millis();
  isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void IndexCommands::ShootHigh::Execute() {
  if(c_TalonRPM(index->getTopVelocity()) > 5500){
    index->setFeed(1);
    index->setBottom(1);
    reachedRPM = true;
  }

  if(reachedRPM == false){
    startTime = frcTools::Time::Millis();
  }

  if(startTime + 2000 > frcTools::Time::Millis()){
    isFinished = true;
  }
}

// Called once the command ends or is interrupted.
void IndexCommands::ShootHigh::End(bool interrupted) {}

// Returns true when the command should end.
bool IndexCommands::ShootHigh::IsFinished() {
  return isFinished;
}
