/**
 * Default Index Command
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 */

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/IndexSubsystem.hpp"

#define TopIndexConverter(rpm) (rpm*2408/600)

/**
 * @brief IndexCommands Namespace
 * 
 * Acts as a group for all of the commands that interact with mainly the index subsystem
 */
namespace IndexCommands{

  /**
   * Initialize The Codex Variable
   * 
   * Used to Store the number of balls currently stored within the index
   */
  extern int codex;

  /**
   * Index Command
   * 
   * Default Command For Index Subsystem
   * 
   * Indexes Balls Using Photoelectric Sensors
   * 
   * @returns FALSE
   * 
   */
  class Index
      : public frc2::CommandHelper<frc2::CommandBase, Index> {
    public:
      Index(IndexSubsystem* indexSubsystem);

      void Initialize() override;

      void Execute() override;

      void End(bool interrupted) override;

      bool IsFinished() override;

    private:
      IndexSubsystem* subsystem;
  };
}