/**
 * @file LowerRobot.hpp
 * @author Jacob Chisholm
 * @brief Raise The Winch (lower the robot) and Hold the Position
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
}

// Called when the command is initially scheduled.
void ClawCommands::ClawDown::Initialize() {
  claw->set(c_TalonUPR(-1000));
}

// Called once the command ends or is interrupted.
void ClawCommands::ClawDown::End(bool interrupted) {
  claw->resetPosition();
  claw->set(ControlMode::MotionMagic, 0);
}