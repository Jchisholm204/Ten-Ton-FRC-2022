/**
 * @file ClawDown.hpp
 * @author Jacob Chisholm
 * @brief Lower The Claw (Grab The Bar) and Hold the Position
 * @version 2.2
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "commands/HangCommands/ClawDown.hpp"
#include "Constants.h"

using namespace HangCommands;

ClawCommands::ClawDown::ClawDown(ClawSubsystem* sys_claw) : claw{sys_claw}{
  AddRequirements(claw);
  SetName("Claw Down");
}

// Called when the command is initially scheduled.
void ClawCommands::ClawDown::Initialize() {
  claw->set(c_TalonUPR(3000));
}

// Called every Scheduler Call
void ClawCommands::ClawDown::Execute() {
  if(claw->getPot() > kHang::Claw::PotLowerLimit){
    claw->set(c_TalonUPR(-1000));
  }
  else{
    claw->set(c_TalonUPR(-3000));
  }
}

// Called once the command ends or is interrupted.
void ClawCommands::ClawDown::End(bool interrupted) {
  claw->resetPosition();
  claw->set(ControlMode::MotionMagic, 0);
}

// Returns True When The Command Should End
bool ClawCommands::ClawDown::IsFinished(){
  return false;//claw->getLowerLimit();
}