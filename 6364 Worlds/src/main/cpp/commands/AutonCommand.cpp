// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


// Include all of Our Commands
#include "commands/AutonCommand.hpp"
#include "commands/DriveCommands/DriveDist.hpp"
#include "commands/IntakeCommands/Intake.hpp"
#include "commands/IndexCommands/ShootLow.hpp"
#include "commands/IndexCommands/AutoIndex.hpp"

// Include all of the WPI Command Group Types
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/ParallelDeadlineGroup.h>
/*
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
*/
AutonCommand::AutonCommand(DriveSubsystem* driveSys, IntakeSubsystem* intakeSys, IndexSubsystem* indexSys) {
  AddCommands(
        // Lower Rear Intake, Drive Backwards while Indexing
    IntakeCommands::Intake(intakeSys, true, false, true),
    frc2::ParallelRaceGroup{
      DriveCommands::DriveDist(driveSys, 30000, 0.07, true),
      IndexCommands::AutoIndex(indexSys)
    },

    //Drive to Goal
    frc2::ParallelCommandGroup{
      DriveCommands::DriveDist(driveSys, 30000, 0.07, true),
      frc2::InstantCommand([indexSys] {indexSys->setTop(1);})
    }
  );
}
