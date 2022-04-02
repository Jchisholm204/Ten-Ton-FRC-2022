/**
 * @file Manual.cpp
 * @author Jacob Chisholm
 * TEAM: 6364
 * @brief Manual Control of the Index
 * @version 0.1
 * @date 2022-03-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "commands/IndexCommands/Manual.hpp"
#include "RobotContainer.h"
#include <frc/smartdashboard/SmartDashboard.h>

IndexCommands::Manual::Manual(IndexSubsystem* sys_index) : index{sys_index} {
  AddRequirements(index);
}

// Called when the command is initially scheduled.
void IndexCommands::Manual::Initialize() {

  frc::SmartDashboard::PutString("Indexing", "Manual");

  index->setTop(0);
  index->setBottom(0);
  index->setFeed(0);
}

// Called repeatedly when this Command is scheduled to run
void IndexCommands::Manual::Execute() {

  // Control the top Indexer with the Left Joystick
  if(partner.GetLeftY() < -0.6){
    index->setTop(0.5);
  }
  else if(partner.GetLeftY() < -0.4){
    index->setTop(0.3);
  }
  else if(partner.GetLeftY() < -0.2){
    index->setTop(0.15);
  }

  else if(partner.GetLeftY() > 0.6){
    index->setTop(-0.5);
  }
  else if(partner.GetLeftY() > 0.4){
    index->setTop(-0.3);
  }
  else if(partner.GetLeftY() > 0.2){
    index->setTop(-0.15);
  }
  else{
    index->setTop(0);
  }

  // Control the Bottom and Feed Indexers with the Right Joystick
  if(partner.GetRightY() > 0.6){
    index->setBottom(-1);
    index->setFeed(-1);
  }
  else if(partner.GetRightY() > 0.4){
    index->setBottom(-0.5);
    index->setFeed(-0.5);
  }
  else if(partner.GetRightY() > 0.2){
    index->setBottom(-0.2);
    index->setFeed(-0.2);
  }

  else if(partner.GetRightY() < -0.6){
    index->setBottom(1);
    index->setFeed(1);
  }
  else if(partner.GetRightY() < -0.4){
    index->setBottom(0.5);
    index->setFeed(0.5);
  }
  else if(partner.GetRightY() < -0.2){
    index->setBottom(0.2);
    index->setFeed(0.2);
  }
  else{
    index->setBottom(0);
    index->setFeed(0);
  }
}

// Called once the command ends or is interrupted.
void IndexCommands::Manual::End(bool interrupted) {
  index->setTop(0);
  index->setBottom(0);
  index->setFeed(0);

  frc::SmartDashboard::PutString("Indexing", "Disabled");
  
}

// Returns true when the command should end.
bool IndexCommands::Manual::IsFinished() {
  return false;
}
