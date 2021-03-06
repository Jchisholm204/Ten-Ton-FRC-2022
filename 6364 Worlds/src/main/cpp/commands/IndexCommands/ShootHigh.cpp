/**
 * @file ShootHigh.hpp
 * @author Jacob Chisholm
 * @brief Index High Shot Command
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "commands/IndexCommands/ShootHigh.hpp"
#include "Constants.h"
#include "tools/Tools.hh"
#include "commands/IndexCommands/Index.hpp"
#include "frc/smartdashboard/SmartDashboard.h"

IndexCommands::ShootHigh::ShootHigh(IndexSubsystem* sys_index) : index{sys_index}, isFinished{false}, reachedRPM{false} {
  AddRequirements(index);
  SetName("High Shot");
}

// Called when the command is initially scheduled.
void IndexCommands::ShootHigh::Initialize() {

  frc::SmartDashboard::PutString("Indexing", "High Shot");

  index->setFeed(0);
  index->setBottom(0);
  index->setTopVel(c_TalonUPR(6300));
  //index->setTop(1);

  startTime = frcTools::Time::Millis();
  spinUpTime = frcTools::Time::Millis();
  isFinished = false;
  reachedRPM = false;
  IndexCommands::codex = 0;
}

// Called repeatedly when this Command is scheduled to run
void IndexCommands::ShootHigh::Execute() {
  
  if(index->getTopVelocity() > 17000 && reachedRPM == false){
    index->setBottom(1);
    reachedRPM = true;
    spinUpTime = frcTools::Time::Millis();
  }

  if(reachedRPM && (spinUpTime + 666 < frcTools::Time::Millis())){
    index->setFeed(1);
  }

  if(frcTools::Time::Millis() > startTime + 3000){
    isFinished = true;
  }
}

// Called once the command ends or is interrupted.
void IndexCommands::ShootHigh::End(bool interrupted) {
  frc::SmartDashboard::PutString("Indexing", "Disabled");
}

// Returns true when the command should end.
bool IndexCommands::ShootHigh::IsFinished() {
  return isFinished;
}
