/**
 * @file WinchDown.hpp
 * @author Jacob Chisholm
 * @brief Lower The Winch and Hold the Position
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "commands/HangCommands/WinchDown.hpp"
#include "Constants.h"
#include "RobotContainer.h"

using namespace HangCommands;

WinchCommands::WinchDown::WinchDown(WinchSubsystem* sys_winch) : winch{sys_winch}{
  AddRequirements(winch);
}

// Called when the command is initially scheduled.
void WinchCommands::WinchDown::Initialize() {
  winch->set(c_TalonUPR(-3000));
}

void WinchCommands::WinchDown::Execute(){

  // Vibrate Controller if Winch Solenoid Active while trying to winch down
  if(winch->getSolenoid() == true){
    partner.SetRumble(frc::GenericHID::RumbleType::kLeftRumble, 2);
    partner.SetRumble(frc::GenericHID::RumbleType::kRightRumble, 2);
  }
  else {
    partner.SetRumble(frc::GenericHID::RumbleType::kLeftRumble, 0);
    partner.SetRumble(frc::GenericHID::RumbleType::kRightRumble, 0);   
  }
}

// Called once the command ends or is interrupted.
void WinchCommands::WinchDown::End(bool interrupted) {
  winch->resetPosition();
  winch->set(ControlMode::MotionMagic, 0);
  partner.SetRumble(frc::GenericHID::RumbleType::kLeftRumble, 0);
  partner.SetRumble(frc::GenericHID::RumbleType::kRightRumble, 0);
}

bool WinchCommands::WinchDown::IsFinished(){
  return winch->getLowerLimit();
}
