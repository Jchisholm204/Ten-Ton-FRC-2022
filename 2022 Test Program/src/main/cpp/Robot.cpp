// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include <math.h>


void Robot::RobotInit() {
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
  //frc2::CommandScheduler::GetInstance().Run();
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


/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
    double yPow = 0.5*exponential(-master.GetLeftY(), 1.7,  0.07, 0.01);
    double xPow = 0.25*exponential(master.GetRightX(), 1.55, 0.07, 0.01);

  rightDrive.Set(yPow - xPow);
  leftDrive.Set(yPow + xPow);
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
