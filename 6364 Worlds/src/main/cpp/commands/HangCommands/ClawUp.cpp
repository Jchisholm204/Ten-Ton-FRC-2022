/**
 * @file LowerRobot.hpp
 * @author Jacob Chisholm
 * @brief Raise The Winch (lower the robot) and Hold the Position
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
}

// Called when the command is initially scheduled.
void ClawCommands::ClawUp::Initialize() {
  claw->set(c_TalonUPR(-6000));
}

// Called once the command ends or is interrupted.
void ClawCommands::ClawUp::End(bool interrupted) {
  claw->resetPosition();
  claw->set(ControlMode::MotionMagic, 0);
}