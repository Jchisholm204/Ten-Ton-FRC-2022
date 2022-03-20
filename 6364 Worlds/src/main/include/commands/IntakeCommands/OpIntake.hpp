/**
 * @file OpIntake.hpp
 * @author Jacob Chisholm
 * @brief Simple Dual Controller Intake Program
 * 
 * @copyright Copyright (c) 2022
 * 
 * Features:
 *  Intake Solenoid Auto Deployment
 *  FUTURE: Jam detection auto lifts intake to unjam using amperage detection
 * 
 */
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/IntakeSubsystem.hpp"

/**
 * @brief IntakeCommands Namespace
 * 
 * Acts as a group for all of the commands that interact with mainly the intake subsystem
 */
namespace IntakeCommands{

  /**
   * OpIntake Command:
   * Runs Operator Intake Code When Scheduled
   */
  class OpIntake
      : public frc2::CommandHelper<frc2::CommandBase, OpIntake> {
  public:
    /**
     * Creates a new Operator Intake Command.
     *
     * @param SubSystem_intake The subsystem used by this command.
     */
    explicit OpIntake(IntakeSubsystem* SubSystem_intake);
    
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

}