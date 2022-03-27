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

#include "frc/smartdashboard/SmartDashboard.h"

IndexCommands::BackFeed::BackFeed(IndexSubsystem* sys_index) : index{sys_index}, isFinished{false}, feedChecked{false}{
  AddRequirements(index);
}

// Called when the command is initially scheduled.
void IndexCommands::BackFeed::Initialize() {
  feedChecked = false;
}

// Called repeatedly when this Command is scheduled to run
void IndexCommands::BackFeed::Execute() {

  if(index->getFeedBall()){
    feedChecked = true;
    index->setFeed(0);
  }

  if(feedChecked == true && index->getBotPE() == false){
    index->setBottom(-0.525);
    index->setTop(ControlMode::PercentOutput, -0.2);
  }

  if(feedChecked == true && index->getBotPE() == true){
    index->setBottom(0);
    index->setTop(ControlMode::PercentOutput, 0);
    index->setFeed(0);
    isFinished = true;
  }
  

  if(feedChecked == false){
    index->setBottom(-0.75);
    index->setFeed(-0.6);
    index->setTop(ControlMode::PercentOutput, 0);
  }
}

// Called once the command ends or is interrupted.
void IndexCommands::BackFeed::End(bool interrupted) {
    index->setBottom(0);
    index->setTop(ControlMode::PercentOutput, 0);
    index->setFeed(0);
}

// Returns true when the command should end.
bool IndexCommands::BackFeed::IsFinished() {
  return isFinished;
}
