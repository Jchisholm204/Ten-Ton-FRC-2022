/**
 * @file Manual.hpp
 * @author Jacob Chisholm
 * TEAM: 6364
 * @brief Manual Control of the Index
 * @version 0.1
 * @date 2022-03-25
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
   * @brief Manual Index Operation Command
   * 
   */
  class Manual
      : public frc2::CommandHelper<frc2::CommandBase, Manual> {
  public:
    Manual(IndexSubsystem* sys_index);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

  private:
    IndexSubsystem* index;
  };
}