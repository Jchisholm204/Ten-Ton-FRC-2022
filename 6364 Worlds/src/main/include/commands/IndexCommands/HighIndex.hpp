/**
 * High Goal Indexing Command : Similar to -> Auton Index Command
 * Utilizes Feed and Lower Index to store balls - leaves top indexer empty
 * 
 * Similar to Auton Indexing but has the ability to use color sorting. Something not necessary for autonomous.
 * High Goal Indexing also keeps the Top Index Motor Running.
 *  This serves two purposes -> First, to reduce the inital amp draw during shooting from the F500 on the Top Index
 *                              Second, this makes it less obvious that we are going for high goal, 
 *                                      and allows a faster switch to low if necessary
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
   * High Goal Index Command
   * 
   * Indexes Balls Using one Photoelectric Sensor and one REV Proximity Sensor
   * 
   * @returns FALSE
   * 
   */
  class HighIndex
      : public frc2::CommandHelper<frc2::CommandBase, HighIndex> {
    public:
      HighIndex(IndexSubsystem* indexSubsystem);

      void Initialize() override;

      void Execute() override;

      void End(bool interrupted) override;

      bool IsFinished() override;

    private:
      IndexSubsystem* subsystem;
  };
}