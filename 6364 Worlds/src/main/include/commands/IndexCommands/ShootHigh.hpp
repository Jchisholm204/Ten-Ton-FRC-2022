/**
 * @file ShootHigh.hpp
 * @author Jacob Chisholm
 * @brief Index High Shot Command
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
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
   * @brief Index Shoot High Command
   * 
   * Shoot two balls in the High Goal
   * 
   * @link BackFeed.hpp @endlink
   * 
   * @returns TRUE after kShootTime has elapsed
   * 
   */
  class ShootHigh
      : public frc2::CommandHelper<frc2::CommandBase, ShootHigh> {
  public:
    ShootHigh(IndexSubsystem* sys_index);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

    private:
      IndexSubsystem* index;
      bool isFinished;
      bool reachedRPM;
      double startTime;
      double spinUpTime;
  };
}