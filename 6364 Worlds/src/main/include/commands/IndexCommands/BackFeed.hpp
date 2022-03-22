/**
 * Index Back-Feed Command
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * Lowers the balls from the top two indexers into the feed and bottom index.
 * 
 * This clears the top index giving the Falcon 500 room to speed up in order to shoot high
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
namespace IndexCommands {

  /**
   * @brief BackFeed Index Command
   * 
   * Backfeeds the balls through the index system using the bottom photoelectric sensor
   * and the proximity function of the color sensor
   * 
   * @returns TRUE once the top ball has settled in the bottom indexer
   * 
   */
  class BackFeed
      : public frc2::CommandHelper<frc2::CommandBase, BackFeed> {
  public:
    BackFeed(IndexSubsystem* sys_index);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

  private:
    IndexSubsystem* index;
    bool isFinished;
    bool feedChecked;
  };
}