#include "commands/OpDriveCommand.hpp"
#include "RobotContainer.h"
#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <math.h>

OpDriveCommand::OpDriveCommand(DriveSubsystem* SubSystem_Drive) : drive{SubSystem_Drive}{
    AddRequirements(drive);
}

/**
 * 
* @param joyVal Input Joystick Value
* @param exPower Power for the Expo Function (1, 2)
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
            power = power*joySign*5250;
        }
        return power;
    }

void OpDriveCommand::Execute(){
    /** NOTE:
     * Exponential Drive Variables should be changed within the Talon.cpp configuration file for the iLeft and iRight Motors
     * SmartDashboard is an unnessasary debugging tool, the lines referencing may be commented out
     * drive->arcadeDrive uses ControlMode::Velocity by default
     */
    double Ypow = exponential(master.GetLeftY(), 1.4,  0.1, 0.01);
    double Xpow = 0.6*exponential(master.GetRightX(), 1.4, 0.1, 0.01);
    frc::SmartDashboard::PutNumber("Drive Power", Ypow);
    frc::SmartDashboard::PutNumber("Turn Power", Xpow);
    frc::SmartDashboard::PutNumber("joy", master.GetLeftY());
    drive->arcadeDrive(Ypow, Xpow);
}

void OpDriveCommand::End(bool interrupted){
    drive->set(ControlMode::PercentOutput, 0, 0);
}