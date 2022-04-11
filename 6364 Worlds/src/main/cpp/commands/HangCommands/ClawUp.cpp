/**
 * @file ClawUp.hpp
 * @author Jacob Chisholm
 * @brief Raise The Claw (Release the bar) and Hold the Position
 * @version 2.2
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "commands/HangCommands/ClawUp.hpp"
#include "Constants.h"

using namespace HangCommands;

ClawCommands::ClawUp::ClawUp(ClawSubsystem* sys_claw) : claw{sys_claw}{
  AddRequirements(claw);
  SetName("Claw Up");
}

// Called when the command is initially scheduled.
void ClawCommands::ClawUp::Initialize() {
  claw->set(c_TalonUPR(-6000));
}

// Called every Scheduler Call
void ClawCommands::ClawUp::Execute() {
  if(claw->getPot() < kHang::Claw::PotUpperLimit){
    claw->set(c_TalonUPR(-3000));
  }
  else{
    claw->set(c_TalonUPR(-6000));
  }
}

// Called once the command ends or is interrupted.
void ClawCommands::ClawUp::End(bool interrupted) {
  claw->resetPosition();
  claw->set(ControlMode::MotionMagic, 0);
}

// Returns True When The Command Should End
bool ClawCommands::ClawUp::IsFinished(){
  return false;
}