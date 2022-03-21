// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IndexCommands/BackFeed.hpp"

#include "commands/IndexCommands/Index.hpp"

IndexCommands::BackFeed::BackFeed(IndexSubsystem* sys_index) : index{sys_index}, isFinished{false}, feedChecked{false}{
  AddRequirements(index);
}

// Called when the command is initially scheduled.
void IndexCommands::BackFeed::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void IndexCommands::BackFeed::Execute() {

  if(index->getFeedBall()){
    feedChecked = true;
    index->setFeed(0);
  }

  if(feedChecked == true && index->getBotPE() == false){
    index->setBottom(-0.35);
    index->setTop(ControlMode::PercentOutput, -0.5);
  }

  if(feedChecked == true && index->getBotPE() == true){
    index->setBottom(0);
    index->setTop(ControlMode::PercentOutput, 0);
    index->setFeed(0);
    isFinished = true;
  }
  

  if(feedChecked == false){
    index->setBottom(-1);
    index->setFeed(-0.35);
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
