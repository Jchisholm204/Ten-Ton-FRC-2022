/**
 * @file OpDrive.cpp
 * @author Jacob Chisholm
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * @brief Simple Operator Drive using Exponential and Closed Loop Velocity Control
 * 
 */


#include "commands/DriveCommands/OpDrive.hpp"
#include "RobotContainer.h"
#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <math.h>

DriveCommands::OpDrive::OpDrive(DriveSubsystem* SubSystem_Drive) : drive{SubSystem_Drive}{
    AddRequirements(drive);
    SetName("Operator Drive");
}

    /**
    * 
    * @param joyVal Input Joystick Value
    * @param exPower Power for the Expo Function (1, 2, 1.4)
    * @param joyDead Controller Deadzone
    * @param motorMin Minimum motor output to start moving
    * @return Motor Output With an Exponential Curve
    */
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

void DriveCommands::OpDrive::Execute(){
    /** NOTE:
     * Exponential Drive Variables should be changed within the Talon.cpp configuration file for the iLeft and iRight Motors
     * SmartDashboard is an unnecessary debugging tool, the lines referencing may be commented out
     * drive->arcadeDrive uses ControlMode::Velocity by default
     */
    double Ypow = 1.0*exponential(-master.GetLeftY(), 1.7,  0.07, 0.01);
    double Xpow = 0.75*exponential(master.GetRightX(), 1.55, 0.07, 0.01);
    //frc::SmartDashboard::PutNumber("Drive Power", Ypow);
    //frc::SmartDashboard::PutNumber("Turn Power", Xpow);
    //frc::SmartDashboard::PutNumber("joy", master.GetLeftY());
    drive->set(Ypow+Xpow, Ypow-Xpow);
}

void DriveCommands::OpDrive::End(bool interrupted){
    drive->set(0);
}