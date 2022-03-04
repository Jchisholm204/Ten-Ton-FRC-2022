// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ReRunAuto.hpp"
#include "frc/DriverStation.h"
#include "RobotContainer.h"
#include "frc/Filesystem.h"
#include "Constants.h"

ReRunAuto::ReRunAuto(DriveSubsystem *driveSub, IndexSubsystem *indexSub, IntakeSubsystem *intakeSub) : drive{driveSub}, index{indexSub}, intake{intakeSub} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveSub);
  AddRequirements(indexSub);
  AddRequirements(intakeSub);
}

/**
 * When the ReRun Program reaches the End of the Data File,
 * It will automatically remove itself from the FRC Scheduler,
 * 
 * It does this by setting this varable to TRUE
 */
bool endofFile = false;

// Data File Header Within the Code
FILE * runFile;

// Called when the command is initially scheduled.
void ReRunAuto::Initialize() {

  // Use the Auton Selected by SmartDashboard to Open a ReRun Data File
  int SA = SelectedAuto.GetSelected();

  switch (SA) {

    /** All Auton Data Files are Stored within the ReRun folder
     *  The ReRun folder can be accessed through:
     *  A: FTP access @ ftp://10.TE.AM.2/ from within any FTP capable file manager
     *  OR
     *  B: Through code @ "/home/lvuser/rerun"
     */

    case auton_s::NoAuto:
    // No Auto: Print Confirmation Error and remove the auto from the scheduler
    printf("SELECTED AUTO: No Auto");
      endofFile = true;
      break;
    case auton_s::Test:
      // Open the Test Auto
      runFile = fopen("/home/lvuser/rerun/test.txt", "r");
      break;
    case auton_s::Left1:
      runFile = fopen("/home/lvuser/rerun/Left1.txt", "r");
      break;
    case auton_s::Left2:
      runFile = fopen("/home/lvuser/rerun/Left2.txt", "r");
      break;
    case auton_s::Right1:
      runFile = fopen("/home/lvuser/rerun/Right1.txt", "r");
      break;
    case auton_s::Right2:
      runFile = fopen("/home/lvuser/rerun/Right2.txt", "r");
      break;
    default:
      // ReRun Does NOT have a "Default" option, it simply will not run an auto
      // However, if we point it to a nonexistent file, bad things are possible,
      // Therefore, if we encounter the "default" we must end the task as if we are indending on not running an auto
      endofFile = true;
      printf("FRun Playback Error: Unknown Auto");
      break;
  };
}

static double dr/*Right Drive Velocity*/, dl/*Left Drive Velocity*/, ifp/*Intake Front Power*/, ibp/*Intake Rear Power*/;
static int is/*Index State*/;
static bool isf/*Intake Front Pneumatic State*/, isr/*Intake Rear Pneumatic State*/; // ABOUT: Pneumatic States: true == down | false == up

// Called repeatedly when this Command is scheduled to run
void ReRunAuto::Execute() {

  // Scan the Data File
  fscanf(runFile, "%lf %lf %i %lf %lf %d %d", &dr, &dl, &is, &ifp, &ibp, &isf, &isr);

  // ReRun Drive Playback
  drive->set(ControlMode::Velocity, dl, dr);

  // ReRun Index Playback
  if(status_running == kIndex::status::OFF){
    index->stop();
  }
  else if(status_running == kIndex::status::RUNNING){
    index->runCodex();
    // Run Feeder Motor (Sideways Index Module)
    if(index->getCodex() == 2){
        index->setFeed(ControlMode::PercentOutput, 0.1); //Slow down when index full
    }
    else{
        index->setFeed(ControlMode::PercentOutput, 1);
    }
  }
  else if(status_running == kIndex::status::SHOOT){
    index->shoot(1);
  }
  else if(status_running == kIndex::status::SHOT){
    index->setTop(ControlMode::PercentOutput, 1);
    index->setBot(ControlMode::PercentOutput, 0);
    index->resetCodex();
  }
  else{printf("STATUS_RUNNING OVERFLOW |@ ReRun Playback @|");};

  // ReRun Intake Playback

  intake->setFront(ControlMode::PercentOutput, ifp);
  intake->setRear(ControlMode::PercentOutput, ibp);

  if(isf == true){
    intake->lower(true, false);
  }
  if(isr == true){
    intake->lower(false, true);
  }
  if(isf == false){
    intake->raise(true, false);
  }
  if(isr == false){
    intake->raise(false, true);
  }

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
