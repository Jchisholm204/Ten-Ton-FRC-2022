#include "commands/OpDriveCommand.hpp"
#include "RobotContainer.h"
#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"

OpDriveCommand::OpDriveCommand(DriveSubsystem* SubSystem_Drive) : drive{SubSystem_Drive}{
    AddRequirements(drive);
}

double OpDriveCommand::exponential(double joystickVal, float driveExp, double joydead, int motorMin){
    joystickVal = joystickVal*100;
    int joySign;
    int joyMax = 100 - joydead;
    int joyLive = abs(joystickVal) - joydead;
    if(joystickVal > 0){joySign = 1;}
    else if(joystickVal < 0){joySign = -1;}
    else{joySign = 0;}
    int power = (joySign * (motorMin + ((100 - motorMin) * (pow(joyLive, driveExp) / pow(joyMax, driveExp)))));
    return power;
}

void OpDriveCommand::Execute(){
    double Ypow = exponential(master.GetLeftY(), 1.2, 10, 5)/100;
    double Xpow = exponential(master.GetRightX(), 1.2, 10, 5)/100;
    frc::SmartDashboard::PutNumber("xPow", Xpow);
    frc::SmartDashboard::PutNumber("yPow", Ypow);
    drive->set(ControlMode::PercentOutput, (Ypow-Xpow), (Ypow + Xpow));
}

void OpDriveCommand::End(bool interrupted){
    drive->set(ControlMode::PercentOutput, 0, 0);
}