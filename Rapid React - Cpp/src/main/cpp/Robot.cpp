// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <thread>
#include <cstdio>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <cameraserver/CameraServer.h>

void Robot::RobotInit() {

  // Enable Digital Control of the Compressor through the Pneumatic Module
  compressor.EnableDigital();

  // Start the Camera Server
  frc::CameraServer::StartAutomaticCapture();

  // ReRun Recording Selector on SmartDashboard
  recording_chooser.AddOption("Enabled", 1);
  recording_chooser.SetDefaultOption("Disabled", 0);
  frc::SmartDashboard::PutData("Recording:", &recording_chooser);

  // ReRun Auton Selection
  SelectedAuto.SetDefaultOption("No Auto", 0);
  SelectedAuto.AddOption("Test", 1);
  frc::SmartDashboard::PutData("Auton Selection",&SelectedAuto);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  r_command_auto_run = m_container.GetAutoCommand();
  r_command_auto_run->Schedule();
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  r_command_opIntake = m_container.GetOpIntakeCommand();
  r_command_opDrive = m_container.GetOpDriveCommand();
  r_command_opIndex = m_container.GetOpIndexCommand();
  r_command_opHang = m_container.GetOpHangCommand();
  r_command_auto_record = m_container.GetRecordCommand();

  if (r_command_opIntake != nullptr) {
    r_command_opIntake->Schedule();
  }

  if (r_command_opDrive != nullptr) {
    r_command_opDrive->Schedule();
  }

  if(r_command_opIndex != nullptr) {
    r_command_opIndex->Schedule();
  }

  if(r_command_opHang != nullptr) {
    r_command_opHang->Schedule();
  }

  if(recording_chooser.GetSelected() == 1 && r_command_auto_record != nullptr){
    r_command_auto_record->Schedule();
  }
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
