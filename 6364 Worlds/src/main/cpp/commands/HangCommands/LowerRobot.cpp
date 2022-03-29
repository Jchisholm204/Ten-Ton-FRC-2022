/**
 * @file LowerRobot.hpp
 * @author Jacob Chisholm
 * @brief Raise The Winch (lower the robot) and Hold the Position
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "commands/HangCommands/LowerRobot.hpp"
#include "Constants.h"

using namespace HangCommands;

WinchCommands::LowerRobot::LowerRobot(WinchSubsystem* sys_winch) : winch{sys_winch}{
  AddRequirements(winch);
}

// Called when the command is initially scheduled.
void WinchCommands::LowerRobot::Initialize() {
  winch->set(c_TalonUPR(3000));
}

// Called once the command ends or is interrupted.
void WinchCommands::LowerRobot::End(bool interrupted) {
  winch->resetPosition();
  winch->set(ControlMode::MotionMagic, 0);
}