/**
 * @file ShootLow.hpp
 * @author Jacob Chisholm
 * @brief Indexer Low Goal Shooting program (Index Interrupt)
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
   * Index Shoot Low Goal Command
   * 
   * @returns TRUE after shoot time has elapsed
   */
  class ShootLow
      : public frc2::CommandHelper<frc2::CommandBase, ShootLow> {
    public:
      ShootLow(IndexSubsystem* indexSubsystem);

      void Initialize() override;

      void Execute() override;

      void End(bool interrupted) override;

      bool IsFinished() override;

    private:
      IndexSubsystem* subsystem;
      bool isFinished;
      double startTime;

  };
}
