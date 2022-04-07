/**
 * Autonomous Command Group
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * Runs all of the Autonomous Commands in Sequence
 */
#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/DriveSubsystem.hpp"
#include "subsystems/IntakeSubsystem.hpp"
#include "subsystems/IndexSubsystem.hpp"
#include "subsystems/LimeLightSubsystem.h"

class AutonCommand
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutonCommand> {
 public:
  AutonCommand(DriveSubsystem* driveSys, IntakeSubsystem* intakeSys, IndexSubsystem* indexSys, LimeLightSubsystem* limelight);
};
