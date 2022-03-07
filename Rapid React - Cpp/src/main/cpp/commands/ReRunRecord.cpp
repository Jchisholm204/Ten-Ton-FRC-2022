// ReRun Record .cpp
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ReRunRecord.hpp"
#include "frc/DriverStation.h"
#include "RobotContainer.h"
#include "frc/Filesystem.h"
#include "Constants.h"

ReRunRecord::ReRunRecord(DriveSubsystem *driveSub, IndexSubsystem *indexSub, IntakeSubsystem *intakeSub) : drive{driveSub}, index{indexSub}, intake{intakeSub} {
  
  /** In a normal Command, you would use the AddRequirements method
  * This is done so that the FRC Scheduler can better manage commands,
  * and prevent access conflicts.
  * 
  * However, as ReRun recording is a read-only operation, and requires the
  * Operator Commands to be running in order to properly record, we simply
  * do not use the AddRequirements method within this file.
  * 
  * This allows us to trick the scheduler into allowing us to have multiple
  * commands accesing the same subsystems at once.
  * 
  * WARNING:
  * This method was done with extreme caution as giving multiple commands
  * access to a single subsystem at once can cause undesired behavior
  * 
  * Example AddRequirements usage below;
  //AddRequirements(driveSub);
  //AddRequirements(indexSub);
  //AddRequirements(intakeSub);
  */
}


// Recording Finished Variable
bool finished = false;

FILE * recFile;

units::second_t startTime = frc::Timer::GetFPGATimestamp();

// Called when the command is initially scheduled.
void ReRunRecord::Initialize() {

  if(frc::DriverStation::IsFMSAttached()){
    printf("FMS CONNECTED: ReRun Recording Disabled");
    finished = true;
  };

  int SA = SelectedAuto.GetSelected();
  switch (SA)
  {
    case auton_s::NoAuto:
    printf("Cannot Record No Auto");
      finished = true;
      break;
    case auton_s::Test:
      recFile = fopen("/home/lvuser/rerun/test.txt", "w");
      break;
    case auton_s::Left1:
      recFile = fopen("/home/lvuser/rerun/Left1.txt", "w");
      break;
    case auton_s::Left2:
      recFile = fopen("/home/lvuser/rerun/Left2.txt", "w");
      break;
    case auton_s::Right1:
      recFile = fopen("/home/lvuser/rerun/Right1.txt", "w");
      break;
    case auton_s::Right2:
      recFile = fopen("/home/lvuser/rerun/Right2.txt", "w");
      break;
    default:
      printf("Cannot record to unknown auto");
      finished = true;
      break;
  };

  startTime = frc::Timer::GetFPGATimestamp();
}

// Called repeatedly when this Command is scheduled to run
void ReRunRecord::Execute() {

  //While Timer < Maximum Alloted Time = Record the Auto
  if(frc::Timer::GetFPGATimestamp() - startTime < units::second_t{15}){
    fprintf(recFile, "%lf\n", drive->getRightVel());
    fprintf(recFile, "%lf\n", drive->getLeftVel());
    fprintf(recFile, "%i\n", status_running);
    fprintf(recFile, "%lf\n", intake->getFrontPow());
    fprintf(recFile, "%lf\n", intake->getRearPow());
    fprintf(recFile, "%d\n", intake->getFrontState());
    fprintf(recFile, "%d\n", intake->getRearState());
  }
  else{ // When Timer > Alloted Time = End the Task
    printf("Recording Finished");
    finished = true;
  }
}

// Called once the command ends or is interrupted.
void ReRunRecord::End(bool interrupted) {
  fprintf(recFile, "0\n0\n0\n0\n0\n0\n0\n");
  fclose(recFile);
  recording_chooser.SetDefaultOption("Disabled", 0);
}

// Returns true when the command should end.
bool ReRunRecord::IsFinished() {
  return finished;
}
