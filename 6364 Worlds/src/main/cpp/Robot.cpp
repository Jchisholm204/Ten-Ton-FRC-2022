/**
 * @file Robot.cpp
 * @author Jacob Chisholm
 * @brief 2022 FRC Robot Code for Ten Ton Robotics Team 6364
 * @date 2022-03-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <cameraserver/CameraServer.h>
#include <frc/RobotController.h>
#include "commands/IndexCommands/Index.hpp"
#include <frc/smartdashboard/SendableChooser.h>

void Robot::RobotInit() {
  // Start the Camera Server
  cs::UsbCamera frontCam = frc::CameraServer::StartAutomaticCapture();
  frontCam.SetFPS(30);
  //frontCam.SetResolution(80, 50); //160 x 120
  frc::CameraServer::StartAutomaticCapture(frontCam);

  topDetectionMethod.SetDefaultOption("IR Sensor", true);
  topDetectionMethod.AddOption("PE Sensor", false);
  frc::SmartDashboard::PutData(&topDetectionMethod);

  teamColor.SetDefaultOption("Disabled", IndexSubsystem::TeamColors::null);
  teamColor.AddOption("Blue", IndexSubsystem::TeamColors::blue);
  teamColor.AddOption("Red", IndexSubsystem::TeamColors::red);
  frc::SmartDashboard::PutData(&teamColor);
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
  //frc::SmartDashboard::PutNumber("Robot AMPS", pdp.GetTotalCurrent());
  //frc::SmartDashboard::PutNumber("FPGA AMPS", frc::RobotController::GetInputCurrent());
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {

  if (autonomousCommand != nullptr) {
    autonomousCommand->Cancel();
    autonomousCommand = nullptr;
  }

  frc::SmartDashboard::PutString("Compressor", "Disabled");
  
}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  autonomousCommand = container.GetAutonomousCommand();

  if (autonomousCommand != nullptr) {
    autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (autonomousCommand != nullptr) {
    autonomousCommand->Cancel();
    autonomousCommand = nullptr;
  }
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
  frc::SmartDashboard::PutNumber("Codex: ", IndexCommands::codex);
  if(compressor.Enabled() == false && frc::SmartDashboard::GetString("Compressor", "Disabled") == "Enabled"){
    frc::SmartDashboard::PutString("Compressor", "Disabled");
  }
  if(compressor.Enabled() == true && frc::SmartDashboard::GetString("Compressor", "Disabled") == "Disabled"){
    frc::SmartDashboard::PutString("Compressor", "Enabled");
  }
}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
