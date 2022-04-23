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
      DriveCommands::DriveDist(driveSys, -80, 3500, true),
      IndexCommands::Index(indexSys)
    },

    // Drive Forwards While Indexing
    frc2::ParallelRaceGroup{
      DriveCommands::DriveDist(driveSys, 10, 3500, false),
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
  SetName("Autonomous Command Group");
  AddCommands(

    // Spin up top Indexer
    frc2::InstantCommand([indexSys] {indexSys->setTop(1);}, {indexSys}),

    // Wait for Speed and Shoot First Ball High
    IndexCommands::ShootHigh(indexSys),

    // Lower Rear Intake, Drive Backwards while Indexing
    frc2::InstantCommand([intakeSys]{
      intakeSys->lower(false, true);
      intakeSys->setRear(1);
      }, {intakeSys}),

    // Drive to Ball
    frc2::ParallelRaceGroup{
      DriveCommands::DriveDist(driveSys, -60, 3500, true),
      IndexCommands::AutoIndex(indexSys)
    },

    // Set up Indexers for Shot
    frc2::InstantCommand([indexSys] {
      indexSys->setTop(1);
      indexSys->setBottom(0);
      indexSys->setFeed(0);
      }, {indexSys}),

    //  Drive Back to Shooting Position
    DriveCommands::DriveDist(driveSys, 0, 2000, false),

    // Raise Intake
    frc2::InstantCommand([intakeSys]{
      intakeSys->raise();
      intakeSys->setRear(0);
      }, {intakeSys}),

    // Align With Goal
    frc2::ParallelRaceGroup{
      DriveCommands::HighGoalDistAlign(driveSys),
      Await(1000)
    },

    // Shoot High - Second Ball
    IndexCommands::ShootHigh(indexSys),

    // Spend Remaining time driving backwards
    DriveCommands::DriveDist(driveSys, -50, 2000, true)
  );
}
