/**
 * @file Stop.cpp
 * @author Jacob Chisholm
 * @brief Stop All Indexer Movement
 * @version 1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "commands/IndexCommands/Stop.hpp"


IndexCommands::Stop::Stop(IndexSubsystem* sys_index, bool isFinished) : index{sys_index}, returnFinished{isFinished}{
  AddRequirements(sys_index);
  SetName("Index Stop Command");
}

// Called when the command is initially scheduled.
void IndexCommands::Stop::Initialize() {
  index->setTop(0);
  index->setBottom(0);
  index->setFeed(0);
}


/**
 * @brief Tell the Scheduler if the command should execute once, or on a continuing basis
 * 
 * @return TRUE for auto use cases where the command should be used and then end
 * @return FALSE for operator control use cases like overriding the Index's default command and stoping the indexing
 */
bool IndexCommands::Stop::IsFinished(){
  return returnFinished;
}
