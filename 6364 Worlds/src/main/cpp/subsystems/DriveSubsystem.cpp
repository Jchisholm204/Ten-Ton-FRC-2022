/**
 * Drive Subsystem
 * 
 * @link DriveSubsystem.hpp
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * Drive Subsystem:
 *    - 4 Falcon FX 500 Motors
 *    - Master and Slave configuration
 *    - Exponential Controller with Deadband
 *    - NavX Gyro
 *    
 */

#include "subsystems/DriveSubsystem.hpp"
#include "Motors.hpp"

DriveSubsystem::DriveSubsystem() :
driveRM{RobotMap::CAN::driveRM},
driveRS{RobotMap::CAN::driveRS},
driveLM{RobotMap::CAN::driveLM},
driveLS{RobotMap::CAN::driveLS},
navX{frc::I2C::kMXP} {

    TalonConfiguration::rightDrive(driveRM);
    TalonConfiguration::rightDrive(driveRS);
    TalonConfiguration::leftDrive(driveLM);
    TalonConfiguration::leftDrive(driveLS);

    driveRS.Follow(driveRM);
    driveLS.Follow(driveLM);
}

void DriveSubsystem::set(ControlMode mode, double leftPow, double rightPow){
    driveRM.Set(mode, rightPow);
    driveLM.Set(mode, leftPow);
}

void DriveSubsystem::set(double leftPow, double rightPow){
    driveRM.Set(ControlMode::Velocity, rightPow);
    driveLM.Set(ControlMode::Velocity, leftPow);
}

void DriveSubsystem::set(ControlMode mode, double iPow){
    driveRM.Set(mode, iPow);
    driveLM.Set(mode, iPow);
}

void DriveSubsystem::set(double velocity){
    driveRM.Set(ControlMode::Velocity, velocity);
    driveLM.Set(ControlMode::Velocity, velocity);
}

double DriveSubsystem::getRightVel(){
    return driveRM.GetSelectedSensorVelocity();
}

double DriveSubsystem::getLeftVel(){
    return driveLM.GetSelectedSensorVelocity();
}

double DriveSubsystem::getRightPos(){
    return driveRM.GetSelectedSensorPosition();
}

double DriveSubsystem::getLeftPos(){
    return driveLM.GetSelectedSensorPosition();
}

double DriveSubsystem::getPos(){
    return (driveRM.GetSelectedSensorPosition() + driveLM.GetSelectedSensorPosition())/2;
}

void DriveSubsystem::resetDrive(){
    driveRM.SetSelectedSensorPosition(0);
    driveLM.SetSelectedSensorPosition(0);
}

double DriveSubsystem::getRotation(){
    return navX.GetYaw();
}

void DriveSubsystem::resetNav(){
    navX.Reset();
}

void DriveSubsystem::calibrateNav(){
    navX.Calibrate();
}

float DriveSubsystem::getNavPos(Direction d){
    if(d == Direction::X){
        return navX.GetDisplacementX();
    }
    else if(d == Direction::Y){
        return navX.GetDisplacementY();
    }
    else if(d == Direction::Z){
        return navX.GetDisplacementZ();
    }
    else{
        return 0;
    }
}

void DriveSubsystem::resetNavPos(){
    navX.ResetDisplacement();
}