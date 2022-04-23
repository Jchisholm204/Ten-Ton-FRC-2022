/**
 * High Goal Indexing Command : Similar to -> Auton Index Command
 * Utilizes Feed and Lower Index to store balls - leaves top indexer empty
 * 
 * Similar to Auton Indexing but has the ability to use color sorting. Something not necessary for autonomous.
 * High Goal Indexing also keeps the Top Index Motor Running.
 *  This serves two purposes -> First, to reduce the inital amp draw during shooting from the F500 on the Top Index
 *                              Second, this makes it less obvious that we are going for high goal, 
 *                                      and allows a faster switch to low if necessary
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 */


#include "commands/IndexCommands/HighIndex.hpp"
#include "commands/IndexCommands/Index.hpp"
#include "frc/smartdashboard/SmartDashboard.h"
#include "RobotContainer.h"

using namespace IndexCommands;

HighIndex::HighIndex(IndexSubsystem* indexSubsystem) : subsystem{indexSubsystem}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subsystem);
  SetName("High Goal Indexing");
}

// Called when the command is initially scheduled.
void HighIndex::Initialize() {
  frc::SmartDashboard::PutString("Indexing", "High");
  subsystem->setTop(0.5);
}

// Called repeatedly when this Command is scheduled to run
void HighIndex::Execute() {

  // 775 Indexing Powers (CTRE Percent Output)
  double feedPow = 1;
  double backPow = 0.6;

  if(teamColor.GetSelected() != IndexSubsystem::TeamColors::null){
    if (teamColor.GetSelected() == subsystem->getBottomBallColor() && codex == 0){
      codex = 1;
    }
  }
  else{
    if ( subsystem->getBotIR() && codex == 0){ codex = 1; };
  }

  if ( subsystem->getFeedPE() && codex == 1 ){ codex = 2; };

  if ( codex == 2 ){
    subsystem->setBottom(0);
    subsystem->setFeed(0);
  }
  else if ( codex == 1 ){
    subsystem->setBottom(0);
    subsystem->setFeed(feedPow);
  }
  else if ( codex == 0 ){
    subsystem->setBottom(backPow);
    subsystem->setFeed(feedPow);
  }
  else{
    printf("Codex OverFlow");
    codex = 0;
  }
}

// Called once the command ends or is interrupted.
void HighIndex::End(bool interrupted) {
  //subsystem->setTop(0);
  //subsystem->setBottom(0);
  //subsystem->setFeed(0);
  frc::SmartDashboard::PutString("Indexing", "~Disabled");
}

// Returns true when the command should end.
bool HighIndex::IsFinished() {
  return false;
}
