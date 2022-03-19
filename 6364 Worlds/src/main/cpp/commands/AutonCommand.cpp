// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutonCommand.hpp"
#include "commands/AutoCommands/DriveDist.hpp"
#include "commands/AutoCommands/IntakeCommand.hpp"
#include "commands/IndexCommands/ShootLow.hpp"
#include "commands/IndexCommands/Index.hpp"

#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/ParallelDeadlineGroup.h>

// Auton Command (simple two ball low goal + Taxi)
AutonCommand::AutonCommand(DriveSubsystem* driveSys, IntakeSubsystem* intakeSys, IndexSubsystem* indexSys) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    // Shoot Low Goal
    IndexCommands::ShootLow(indexSys),

    // Lower Rear Intake, Drive Backwards while Indexing
    frc2::ParallelRaceGroup{
      AutoCommands::IntakeCommand(intakeSys, true, false, true),
      AutoCommands::DriveDist(driveSys, 30000, 0.07, true),
      IndexCommands::Index(indexSys)
    },

    // Drive Forwards While Indexing
    frc2::ParallelRaceGroup{
      AutoCommands::DriveDist(driveSys, 30000, 0.07, false),
      IndexCommands::Index(indexSys)
    },

    // Raise Intake
    AutoCommands::IntakeCommand(intakeSys, false, false, true),

    // Shoot Low Goal
    IndexCommands::ShootLow(indexSys)
  );

}
