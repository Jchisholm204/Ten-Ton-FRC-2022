// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/IntakeSubsystem.hpp"

namespace AutoCommands{

  class IntakeCommand
      : public frc2::CommandHelper<frc2::InstantCommand,
                                  IntakeCommand> {
  public:
    /**
     * Instant Command To Start or Stop the Intakes
     * 
     * @param on TRUE to run the intakes
     * @param front TRUE to apply the command to the front intake
     * @param rear TRUE to apply the command to the rear intake
     * @returns TRUE instantly
     */
    IntakeCommand(IntakeSubsystem* IntakeSubsystem, bool on, bool front, bool rear);

    /**
     * Instant Command To Start or Stop the Intakes
     * 
     * @param on TRUE to run the intakes
     * @returns TRUE instantly
     */
    IntakeCommand(IntakeSubsystem* IntakeSubsystem, bool on);

    void Initialize() override;

    private:
      IntakeSubsystem* intake;
      bool running, f, r;
  };

}
