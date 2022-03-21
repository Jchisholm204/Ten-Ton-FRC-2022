/**
 * @file Intake.hpp
 * @author Jacob Chisholm
 * @brief Simple Instant Command to Interact with the Intakes
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/IntakeSubsystem.hpp"


/**
 * @brief IntakeCommands Namespace
 * 
 * Acts as a group for all of the commands that interact with mainly the intake subsystem
 */
namespace IntakeCommands{

  class Intake
      : public frc2::CommandHelper<frc2::InstantCommand,
                                  Intake> {
  public:
    /**
     * Instant Command To Start or Stop the Intakes
     * 
     * @param on TRUE to run the intakes
     * @param front TRUE to apply the command to the front intake
     * @param rear TRUE to apply the command to the rear intake
     * @returns TRUE instantly
     */
    Intake(IntakeSubsystem* IntakeSubsystem, bool on, bool front, bool rear);

    /**
     * Instant Command To Start or Stop the Intakes
     * 
     * @param on TRUE to run the intakes
     * @returns TRUE instantly
     */
    Intake(IntakeSubsystem* IntakeSubsystem, bool on);

    void Initialize() override;

    private:
      IntakeSubsystem* intake;
      bool running, f, r;
  };

}
