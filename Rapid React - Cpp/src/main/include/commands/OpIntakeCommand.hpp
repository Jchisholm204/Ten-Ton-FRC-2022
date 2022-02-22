// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/IntakeSubsystem.hpp"

/**
 * OpIntake Command:
 * Runs Operator Intake Code When Scheduled
 */
class OpIntakeCommand
    : public frc2::CommandHelper<frc2::CommandBase, OpIntakeCommand> {
 public:
  /**
   * Creates a new Operator Intake Command.
   *
   * @param SubSystem_intake The subsystem used by this command.
   */
  explicit OpIntakeCommand(IntakeSubsystem* SubSystem_intake);
  
  /**
   * Runs at the Start of the Command
   */
  void Initialize() override;

  /**
   * Called Repeatedly while the command is scheduled
   */
  void Execute() override;

  /**
   * Runs when the Command us removed from the Scheduler
   * @param interrupted Whether it was interrupted by another command
   */
  void End(bool interrupted) override;

  /** 
   * @return True when the command should be removed from the Scheduler
   */
  bool IsFinished() override;

  private:
    IntakeSubsystem* intake;
};
