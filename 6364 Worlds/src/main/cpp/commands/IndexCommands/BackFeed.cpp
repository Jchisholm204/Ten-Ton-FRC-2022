/**
 * Index Back-Feed Command
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * Lowers the balls from the top two indexers into the feed and bottom index.
 * 
 * This clears the top index giving the Falcon 500 room to speed up in order to shoot high
 * 
 */

#include "commands/IndexCommands/BackFeed.hpp"
#include "commands/IndexCommands/Index.hpp"
#include "tools/Tools.hh"

#include "frc/smartdashboard/SmartDashboard.h"

IndexCommands::BackFeed::BackFeed(IndexSubsystem* sys_index) : index{sys_index}, isFinished{false}, startTime{0}{
  AddRequirements(index);
}

// Called when the command is initially scheduled.
void IndexCommands::BackFeed::Initialize() {

  frc::SmartDashboard::PutString("Indexing", "BackFeed");

  startTime = frcTools::Time::Seconds();
  index->setTop(-0.5);
  index->setBottom(-0.6);
  index->setFeed(-0.6);
}

// Called repeatedly when this Command is scheduled to run
void IndexCommands::BackFeed::Execute() {

  // End Command if there is a ball in the Feed Indexer
  if(index->getFeedBall()){
    isFinished = true;
  }

  // End Command if it has been running for more than four (4) Seconds
  if(startTime + 4 < frcTools::Time::Seconds()){
    isFinished = true;
  }

}

// Called once the command ends or is interrupted.
void IndexCommands::BackFeed::End(bool interrupted) {
    index->setBottom(0);
    index->setTop(0);
    index->setFeed(0);

    frc::SmartDashboard::PutString("Indexing", "Disabled");

}

// Returns true when the command should end.
bool IndexCommands::BackFeed::IsFinished() {
  return isFinished;
}
