
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
   */
  class Stop
      : public frc2::CommandHelper<frc2::CommandBase,
                                  Stop> {
  public:
    Stop(IndexSubsystem* sys_index);

    void Initialize() override;

    bool IsFinished() override;

  private:
    IndexSubsystem* index;
  };
}