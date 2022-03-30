/**
 * Auton Index Command
 * Utilizes Feed and Lower Index to store balls - leaves top indexer empty
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 */

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/IndexSubsystem.hpp"

/**
 * @brief IndexCommands Namespace
 * 
 * Acts as a group for all of the commands that interact with mainly the index subsystem
 */
namespace IndexCommands{

  /**
   * Auton Index Command
   * 
   * Indexes Balls Using one Photoelectric Sensor and one REV Proximity Sensor
   * 
   * @returns FALSE
   * 
   */
  class AutoIndex
      : public frc2::CommandHelper<frc2::CommandBase, AutoIndex> {
    public:
      AutoIndex(IndexSubsystem* indexSubsystem);

      void Initialize() override;

      void Execute() override;

      void End(bool interrupted) override;

      bool IsFinished() override;

    private:
      IndexSubsystem* subsystem;
  };
}