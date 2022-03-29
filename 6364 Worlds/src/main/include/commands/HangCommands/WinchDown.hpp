/**
 * @file WinchDown.hpp
 * @author Jacob Chisholm
 * @brief Lower The Winch and Hold the Position
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
     * Winch Down Command
     * 
     * START: Lowers the Winch
     * END: Uses CTRE Magic Motion to hold the Winches end position
     * 
     */
    class WinchDown
        : public frc2::CommandHelper<frc2::CommandBase, WinchDown> {
    public:
      WinchDown(WinchSubsystem* sys_winch);

      void Initialize() override;

      void Execute() override;

      void End(bool interrupted) override;

      bool IsFinished() override;

      private:
        WinchSubsystem* winch;
    };

  } // Winch Commands

} // namespace HangCommands