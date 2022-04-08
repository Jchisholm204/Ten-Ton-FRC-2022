/**
 * @file ClawDown.hpp
 * @author Jacob Chisholm
 * @brief Lower The Claw (Grab The Bar) and Hold the Position
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/ClawSubsystem.hpp"

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
  namespace ClawCommands {

    /**
     * Winch Lower Robot Command
     * 
     * START: Raises the Winch (slowly)
     * END: Uses CTRE Magic Motion to hold the Winches end position
     * 
     */
    class ClawDown
        : public frc2::CommandHelper<frc2::CommandBase, ClawDown> {
    public:
      ClawDown(ClawSubsystem* sys_claw);

      void Initialize() override;

      void Execute() override;

      void End(bool interrupted) override;

      bool IsFinished() override;

      private:
        ClawSubsystem* claw;
    };

  } // Winch Commands

} // namespace HangCommands