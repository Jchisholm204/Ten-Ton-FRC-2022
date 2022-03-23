/**
 * @file PneumaticControl.hpp
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

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/WinchSubsystem.hpp"

/**
 * Hang Commands Namespace
 * 
 * Contains all of the Commands relating to the Hang
 * 
 */
namespace HangCommands {

  /**
   * Winch Pneumatic Control Command
   * 
   * Winch Subsystem Default Command
   * 
   */
  class PneumaticControl
      : public frc2::CommandHelper<frc2::CommandBase, PneumaticControl> {
  public:
    PneumaticControl(WinchSubsystem* sys_winch);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

  private:
    WinchSubsystem* winch;
  };
}