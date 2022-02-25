#include "commands/OpDriveCommand.hpp"
#include "RobotContainer.h"
#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"

OpDriveCommand::OpDriveCommand(DriveSubsystem* SubSystem_Drive) : drive{SubSystem_Drive}{
    AddRequirements(drive);
}

int OpDriveCommand::exponential(double joystickVal, float driveExp, double joydead, int motorMin, int motorMax){
    joystickVal = joystickVal*motorMax;
    int joySign;
    int joyMax = motorMax - joydead;
    int joyLive = abs(joystickVal) - joydead;
    if(joystickVal > 0){joySign = 1;}
    else if(joystickVal < 0){joySign = -1;}
    else{joySign = 0;}
    int power = (joySign * (motorMin + ((motorMax - motorMin) * (pow(joyLive, driveExp) / pow(joyMax, driveExp)))));
    return power;
}

void OpDriveCommand::Execute(){
    double Ypow = exponential(master.GetLeftY(), 1.2, 0.1, 0.1, 1);
    double Xpow = exponential(master.GetRightX(), 1.2, 0.1, 0.1, 1);
    frc::SmartDashboard::PutNumber("Drive Power", Ypow);
    frc::SmartDashboard::PutNumber("Turn Power", Xpow);
    drive->set(ControlMode::PercentOutput, (Ypow-Xpow), (Ypow + Xpow));
}

void OpDriveCommand::End(bool interrupted){
    drive->set(ControlMode::PercentOutput, 0, 0);
}