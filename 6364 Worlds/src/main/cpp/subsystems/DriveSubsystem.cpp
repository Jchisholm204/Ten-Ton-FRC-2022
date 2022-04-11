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
#include "tools/Motors.hpp"
#include <frc/SPI.h>
#include <frc/smartdashboard/SmartDashboard.h>

DriveSubsystem::DriveSubsystem() :
driveRM{RobotMap::CAN::driveRM},
driveRS{RobotMap::CAN::driveRS},
driveLM{RobotMap::CAN::driveLM},
driveLS{RobotMap::CAN::driveLS},
navX{frc::SPI::kMXP} {

    motorConfiguration::Talon::rightDrive(driveRM);
    motorConfiguration::Talon::rightDrive(driveRS);
    motorConfiguration::Talon::leftDrive(driveLM);
    motorConfiguration::Talon::leftDrive(driveLS);

    driveRS.Follow(driveRM);
    driveLS.Follow(driveLM);

    //frc::SmartDashboard::PutBoolean("Reset Gyro Readings", false);
    SetName("DriveBase");
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

//float maxPitch = 0;
//float minPitch = 0;

void DriveSubsystem::Periodic(){
    frc::SmartDashboard::PutNumber("Gyro Tilt", navX.GetRoll());
    /*
    frc::SmartDashboard::PutNumber("Max Tilt", maxPitch);
    frc::SmartDashboard::PutNumber("Min Tilt", minPitch);
    if(navX.GetRoll() > maxPitch){
        maxPitch = navX.GetRoll();
    }
    if(navX.GetRoll() < minPitch){
        minPitch = navX.GetRoll();
    }

    if(frc::SmartDashboard::GetBoolean("Reset Gyro Readings", false) == true){
        maxPitch = 0;
        minPitch = 0;
         frc::SmartDashboard::PutBoolean("Reset Gyro Readings", false);
    }*/
}