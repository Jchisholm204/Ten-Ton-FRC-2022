#include "subsystems/DriveSubsystem.hpp"
#include "Constants.h"
#include "utilities/Talon.hpp"

DriveSubsystem::DriveSubsystem() : 
driveRM(RobotMap::CAN::driveRM), 
driveRS(RobotMap::CAN::driveRS), 
driveLM(RobotMap::CAN::driveLM), 
driveLS(RobotMap::CAN::driveLS) {

    // Configure the Motors
    TalonConfiguation::rightDrive(driveRM);
    TalonConfiguation::rightDrive(driveRS);
    driveRS.Follow(driveRM); // Set Drive Right Slave to Follow Right Master

    TalonConfiguation::leftDrive(driveLM);
    TalonConfiguation::leftDrive(driveLS);
    driveLS.Follow(driveLM); // Set Left Slave to Follow Left Master

    // Reset the Drive Encoders
    driveRM.SetSelectedSensorPosition(0);
    driveLS.SetSelectedSensorPosition(0);
}

void DriveSubsystem::set(ControlMode mode, double leftPow, double rightPow){
    driveRM.Set(mode, rightPow);
    driveLM.Set(mode, leftPow);
}

void DriveSubsystem::arcadeDrive(double iPow, double turnPow){
    driveRM.Set(ControlMode::Velocity, (iPow + turnPow));
    driveLM.Set(ControlMode::Velocity, (iPow - turnPow));
}

double DriveSubsystem::getRightVel(){
    return driveRM.GetSelectedSensorVelocity();
}

double DriveSubsystem::getLeftVel(){
    return driveLM.GetSelectedSensorVelocity();
}