/**
 * @file LowerRobot.hpp
 * @author Jacob Chisholm
 * @brief Raise The Winch (lower the robot) and Hold the Position
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
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
   * Winch Commands Namespace
   * 
   * Contains all the the commands that interact with the Winch
   * 
   */
  namespace WinchCommands {

    /**
     * Winch Lower Robot Command
     * 
     * START: Raises the Winch (slowly)
     * END: Uses CTRE Magic Motion to hold the Winches end position
     * 
     */
    class LowerRobot
        : public frc2::CommandHelper<frc2::CommandBase, LowerRobot> {
    public:
      LowerRobot(WinchSubsystem* sys_winch);

      void Initialize() override;

      void End(bool interrupted) override;

      private:
        WinchSubsystem* winch;
    };

  } // Winch Commands

} // namespace HangCommands