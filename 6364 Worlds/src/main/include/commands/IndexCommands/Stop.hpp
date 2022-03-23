/**
 * @file Stop.hpp
 * @author Jacob Chisholm
 * @brief Stop All Indexer Movement
 * @version 1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>

#include "subsystems/IndexSubsystem.hpp"

/**
 * @brief IndexCommands Namespace
 * 
 * Acts as a group for all of the commands that interact with mainly the index subsystem
 */
namespace IndexCommands{

  /**
   * Stop The Index
   * @param isFinished What the command should return to the scheduler as Finished
   */
  class Stop
      : public frc2::CommandHelper<frc2::CommandBase,
                                  Stop> {
  public:
    Stop(IndexSubsystem* sys_index, bool isFinished);

    void Initialize() override;

    bool IsFinished() override;

  private:
    IndexSubsystem* index;
    bool returnFinished;
  };
}