// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ReRunAuto.hpp"
#include "frc/DriverStation.h"
#include "RobotContainer.h"
#include "frc/Filesystem.h"

ReRunAuto::ReRunAuto(DriveSubsystem *driveSub, IndexSubsystem *indexSub, IntakeSubsystem *intakeSub) : drive{driveSub}, index{indexSub}, intake{intakeSub} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveSub);
  AddRequirements(indexSub);
  AddRequirements(intakeSub);
}

bool endofFile = false;

FILE * runFile;

// Called when the command is initially scheduled.
void ReRunAuto::Initialize() {

  int SA = SelectedAuto.GetSelected();
  switch (SA)
  {
    case 0:
    printf("SELECTED AUTO: No Auto");
      endofFile = true;
      break;
    case 1:
      runFile = fopen("/home/lvuser/test.txt", "r");
      break;
    default:
      printf("Cannot run to unknown auto");
      break;
  };
}

static double dr, dl;

// Called repeatedly when this Command is scheduled to run
void ReRunAuto::Execute() {
  fscanf(runFile, "%f %f", &dr, &dl);
  drive->set(ControlMode::Velocity, dl, dr);
  endofFile = feof(runFile);
}

// Called once the command ends or is interrupted.
void ReRunAuto::End(bool interrupted) {
  fclose(runFile);
}

// Returns true when the command should end.
bool ReRunAuto::IsFinished() {
  return endofFile;
}
