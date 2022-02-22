#include "commands/OpDriveCommand.hpp"
#include "RobotContainer.h"
#include "Constants.h"

OpDriveCommand::OpDriveCommand(DriveSubsystem* SubSystem_Drive) : drive{SubSystem_Drive}{
    AddRequirements(drive);
}

double OpDriveCommand::exponential(double joystickVal, float driveExp, double joydead, int motorMin){
  int joySign;
  int joyMax = 1 - joydead;
  int joyLive = abs(joystickVal) - joydead;
  if(joystickVal > 0){joySign = 1;}
  else if(joystickVal < 0){joySign = -1;}
  else{joySign = 0;}
  double power = joySign * (motorMin + ((1 - motorMin) * (pow(joyLive, driveExp) / pow(joyMax, driveExp))));
  return power;
}

void OpDriveCommand::Execute(){
    double Ypow = 21000 * exponential(master.GetLeftY(), 1.2, 0.01, 0);
    double Xpow = (21000 * driveConstants::k_opTurnPow) * exponential(master.GetRightX(), 1.2, 0.01, 0);

    drive->arcadeDrive(Ypow, Xpow);
}

void OpDriveCommand::End(bool interrupted){
    drive->set(ControlMode::PercentOutput, 0, 0);
}