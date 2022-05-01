// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/SPI.h>
#include <math.h>

void configMotor(TalonSRX &iMotor, bool inverted){
    // Create the Motor Configuration
    TalonSRXConfiguration motorConfig;
    // Set the Primary Feedback Sensor (configure the motor's encoder)
    motorConfig.primaryPID.selectedFeedbackSensor = FeedbackDevice::CTRE_MagEncoder_Absolute;
    // Configure the Motor's Integrated PID
    motorConfig.slot0.kP = 1.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kI = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kD = 10.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kF = 0.0505; // kF - Feed Forward Value - The Minimum Motor Power Required to Move the Motor

    motorConfig.slot0.integralZone = 0;
    motorConfig.slot0.allowableClosedloopError = 0;
    motorConfig.closedloopRamp = 0.01;

    motorConfig.motionAcceleration = 200;
    motorConfig.motionCruiseVelocity = 22000; //Maximum Speed (encoder units / 100ms) for Magic Motion

    motorConfig.nominalOutputForward = 0.0;
    motorConfig.nominalOutputReverse = 0.0;
    motorConfig.peakOutputForward = 0.4;
    motorConfig.peakOutputReverse = -0.4;

    motorConfig.motionCurveStrength = 0;
    
    // Reset the Motor to Factory Settings before Applying Profile
    iMotor.ConfigFactoryDefault();
    // Apply our Motor Configuration Profile
    iMotor.ConfigAllSettings(motorConfig);
    //Set the Motor Inversion
    iMotor.SetInverted(inverted);
    //Set the Motors Neutral Mode (What it does when no power is being applied)
    iMotor.SetNeutralMode(NeutralMode::Coast);

}

void Robot::RobotInit() {
  NavX.Calibrate();
  NavX.ResetDisplacement();


  configMotor(turretMotor, true);
  
  
  frc::SmartDashboard::PutNumber("Turn", 0);
  frc::SmartDashboard::PutNumber("DispX", 0);
  frc::SmartDashboard::PutNumber("DispY", 0);
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
  frc::SmartDashboard::PutNumber("Turret Position", turretMotor.GetSelectedSensorPosition());
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

}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {

}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {

  frc::SmartDashboard::PutNumber("X", NavX.GetDisplacementX());
  frc::SmartDashboard::PutNumber("Y", NavX.GetDisplacementY());
  frc::SmartDashboard::PutNumber("Z", NavX.GetDisplacementZ());

  int TurretDegrees = (abs(int(turretMotor.GetSelectedSensorPosition()))%4096)*360/4096;

  frc::SmartDashboard::PutNumber("Degrees", TurretDegrees);

  double simXDisp = -NavX.GetDisplacementX();  //frc::SmartDashboard::GetNumber("DispX", 1);
  double simYDisp = 1;  //frc::SmartDashboard::GetNumber("DispY", 1);
  double simTurn = NavX.GetYaw();  //frc::SmartDashboard::GetNumber("Turn", 0);

  double targAngle = atan(simYDisp/simXDisp)*180/3.14159;

  frc::SmartDashboard::PutNumber("targAngle", targAngle);

  double targPosition = (targAngle/180)*4096;

  frc::SmartDashboard::PutNumber("TargPosition", targPosition);

  //turretMotor.Set(ControlMode::MotionMagic, frc::SmartDashboard::GetNumber("Targ", 0));
  turretMotor.Set(ControlMode::MotionMagic, targPosition);


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
