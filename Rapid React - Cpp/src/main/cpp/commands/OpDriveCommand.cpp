#include "commands/OpDriveCommand.hpp"
#include "RobotContainer.h"
#include "Constants.h"

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
    return (joySign * (motorMin + ((100 - motorMin) * (pow(joyLive, driveExp) / pow(joyMax, driveExp)))));
}

void OpDriveCommand::Execute(){
    double Ypow = 2100 * exponential(master.GetLeftY(), 1.2, 1, 0);
    double Xpow = (2100 * driveConstants::k_opTurnPow) * exponential(master.GetRightX(), 1.2, 1, 1);

    drive->arcadeDrive(Ypow, Xpow);
}

void OpDriveCommand::End(bool interrupted){
    drive->set(ControlMode::PercentOutput, 0, 0);
}