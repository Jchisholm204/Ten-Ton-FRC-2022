// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include <math.h>


void Robot::RobotInit() {
    rightDrive.SetInverted(true);
    leftDrive.SetInverted(false);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */

double yPow;
double xPow;
void Robot::RobotPeriodic() {
    frc::SmartDashboard::PutNumber("Throttle RAW", throttle.GetValue());
    frc::SmartDashboard::PutNumber("Steering RAW", steering.GetValue());
  //frc2::CommandScheduler::GetInstance().Run();
      frc::SmartDashboard::PutNumber("Power", yPow);
    frc::SmartDashboard::PutNumber("Steering", xPow);
    
    if(throttle.GetValue() < 1800){
        yPow = -(1800-double(throttle.GetValue()))/500;
    }
    else{
        yPow = 0;
    }

    if(brake.Get()){
        yPow = -yPow/4;
    }

    xPow = 0.5*(steering.GetValue()-2000)/2000;
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {
}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
}

double exponential(double joyVal, double exPower, double joyDead, double motorMin){
    double joySign;
    double joyMax = 1-joyDead;
    double joyLive;
    if(joyVal > 0) {
        joySign = 1;
    }
    else if(joyVal < 0) {
        joySign = -1;
    }
    else {
        joySign = 0;
    };

    joyLive = abs(joyVal) - joyDead;

    double power = (pow(joyLive, exPower) / pow(joyMax, exPower));
    if(isnan(power)){
        power = 0;
    }
    else{
        power = power*joySign*21000;
    }
    return power;
}

double rPow = 0;
double lPow = 0;

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {

    frc::SmartDashboard::PutNumber("Power", yPow);
    frc::SmartDashboard::PutNumber("Steering", xPow);
    frc::SmartDashboard::PutNumber("Left", lPow);
    frc::SmartDashboard::PutNumber("Right", rPow);
    
    if(throttle.GetValue() < 1800){
        yPow = -(1800.0-double(throttle.GetValue()))/450.0;
    }
    else{
        yPow = 0.;
    }

    if(brake.Get()){
        yPow = -(yPow*0.25);
    }
    else{
        yPow = yPow*0.25;
    }

    xPow = (double(steering.GetValue())-2000.)/2000.;

    if(xPow > 0){
        rPow = yPow*(1-abs(xPow));
        lPow = yPow;
    }
    else if(xPow < 0){
        rPow = yPow;
        lPow = yPow*(1-abs(xPow));
    }
    else{
        rPow = yPow;
        lPow = yPow;     
    }


    rightDrive.Set(rPow);
    leftDrive.Set(lPow);
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
