// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ReRunRecord.hpp"
#include "frc/DriverStation.h"
#include "RobotContainer.h"
#include "frc/Filesystem.h"

ReRunRecord::ReRunRecord(DriveSubsystem *driveSub, IndexSubsystem *indexSub, IntakeSubsystem *intakeSub) : drive{driveSub}, index{indexSub}, intake{intakeSub} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveSub);
  AddRequirements(indexSub);
  AddRequirements(intakeSub);
}

bool finished = false;

FILE * recFile;

// Called when the command is initially scheduled.
void ReRunRecord::Initialize() {

  if(frc::DriverStation::IsFMSAttached()){
    printf("FMS CONNECTED: ReRun Recording Disabled");
    finished = true;
  };

  int SA = SelectedAuto.GetSelected();
  switch (SA)
  {
    case 0:
    printf("Cannot Record No Auto");
      finished = true;
      break;
    case 1:
      recFile = fopen("/home/lvuser/test.txt", "w");
      break;
    default:
      printf("Cannot record to unknown auto");
      break;
  };
}

// Called repeatedly when this Command is scheduled to run
void ReRunRecord::Execute() {
  units::second_t startTime = frc::Timer::GetFPGATimestamp();

  if(frc::Timer::GetFPGATimestamp() - startTime < units::second_t{15}){
    fprintf(recFile, "%lf\n",drive->getRightVel());
    fprintf(recFile, "%lf\n",drive->getRightVel());
  }
  else{
    printf("Recording Finished");
    finished = true;
  }
}

// Called once the command ends or is interrupted.
void ReRunRecord::End(bool interrupted) {
  fprintf(recFile, "0\n0\n");
  fclose(recFile);
  recording_chooser.SetDefaultOption("Disabled", 0);
}

// Returns true when the command should end.
bool ReRunRecord::IsFinished() {
  return finished;
}
