/**
 * @file PneumaticControl.cpp
 * @author Jacob Chisholm
 * @brief Partner Control of Hang Pneumatics System
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 * Partner can press UP on the d-pad to fire the Solenoid
 * OR
 * Partner can press DOWN on the d-pad to release pressure from the Solenoid
 * 
 * The Solenoid is single action attached to a double action Pneumatic
 * 
 * This command is the default command for the Winch Subsystem
 * 
 */

#include "commands/HangCommands/PneumaticControl.hpp"
#include "RobotContainer.h"

HangCommands::PneumaticControl::PneumaticControl(WinchSubsystem* sys_winch) : winch{sys_winch}{
  AddRequirements(winch);
}

// Called when the command is initially scheduled.
void HangCommands::PneumaticControl::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void HangCommands::PneumaticControl::Execute() {

  if(partner.GetPOV(0) == 0){
    winch->setSolenoid(true);
  }

  if(partner.GetPOV(0) == 180){
    winch->setSolenoid(false);
  }

}

// Called once the command ends or is interrupted.
void HangCommands::PneumaticControl::End(bool interrupted) {}

// Always Returns FALSE as this is the default command assigned to the Winch Subsystem
// Default Commands MUST allways return false
bool HangCommands::PneumaticControl::IsFinished() {
  return false;
}
