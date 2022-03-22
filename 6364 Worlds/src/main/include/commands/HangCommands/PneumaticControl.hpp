// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/WinchSubsystem.hpp"

/**
 * Hang Commands Namespace
 * 
 * Contains all of the Commands relating to the Hang
 * 
 */
namespace HangCommands {

  /**
   * Winch Pneumatic Control Command
   * 
   * Winch Subsystem Default Command
   * 
   */
  class PneumaticControl
      : public frc2::CommandHelper<frc2::CommandBase, PneumaticControl> {
  public:
    PneumaticControl(WinchSubsystem* sys_winch);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

  private:
    WinchSubsystem* winch;
  };
}