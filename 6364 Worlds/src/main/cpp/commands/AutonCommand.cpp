// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


// Include all of Our Commands
#include "commands/AutonCommand.hpp"
#include "commands/Commands.inc"

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
AutonCommand::AutonCommand(DriveSubsystem* driveSys, IntakeSubsystem* intakeSys, IndexSubsystem* indexSys, LimeLightSubsystem* limelight) {
  AddCommands(

    // Spin up top Indexer
    frc2::InstantCommand([indexSys] {indexSys->setTop(1);}, {indexSys}),
    // Drive to Shooting Position
    DriveCommands::DriveDist(driveSys, -20, 0.07, true),
    // Wait for Speed and Shoot First Ball High
    IndexCommands::ShootHigh(indexSys),

    // Lower Rear Intake, Drive Backwards while Indexing
    IntakeCommands::Intake(intakeSys, true, false, true),
    frc2::ParallelRaceGroup{
      DriveCommands::DriveDist(driveSys, -45, 0.07, true),
      IndexCommands::AutoIndex(indexSys)
    },

    //  Drive Back to Shooting Position
    frc2::ParallelCommandGroup{
      DriveCommands::DriveDist(driveSys, 45, 0.07, true),
      frc2::InstantCommand([indexSys] {indexSys->setTop(1);}, {indexSys})
    },
    // Shoot High - Second Ball
    IndexCommands::ShootHigh(indexSys)
  );
}
