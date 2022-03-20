// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


// Include all of Our Commands
#include "commands/AutonCommand.hpp"
#include "commands/DriveCommands/DriveDist.hpp"
#include "commands/IntakeCommands/Intake.hpp"
#include "commands/IndexCommands/ShootLow.hpp"
#include "commands/IndexCommands/Index.hpp"

// Include all of the WPI Command Group Types
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
      IntakeCommands::Intake(intakeSys, true, false, true),
      DriveCommands::DriveDist(driveSys, 30000, 0.07, true),
      IndexCommands::Index(indexSys)
    },

    // Drive Forwards While Indexing
    frc2::ParallelRaceGroup{
      DriveCommands::DriveDist(driveSys, 30000, 0.07, false),
      IndexCommands::Index(indexSys)
    },

    // Raise Intake
    IntakeCommands::Intake(intakeSys, false, false, true),

    // Shoot Low Goal
    IndexCommands::ShootLow(indexSys)
  );

}
