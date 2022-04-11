/**
 * Intake Subsystem
 * 
 * @link IntakeSubsystem.hpp
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * Intake Subsystem:
 *    - Front and Rear Intakes
 *    - 2 Bag Motors controlled by CTRE Talon SRX
 *    - 2 double action solenoids (one for front / one for rear)
 *    
 */

#include "subsystems/IntakeSubsystem.hpp"
#include "tools/Motors.hpp"

IntakeSubsystem::IntakeSubsystem() :
    frontMtr{RobotMap::CAN::Intake_front}, 
    rearMtr{RobotMap::CAN::Intake_rear}, 
    frontSolenoid{frc::PneumaticsModuleType::CTREPCM, RobotMap::PCM::frontIntake}, 
    rearSolenoid{frc::PneumaticsModuleType::CTREPCM, RobotMap::PCM::rearIntake} 
    {
        motorConfiguration::Talon::intake(frontMtr, true);
        motorConfiguration::Talon::intake(rearMtr, false);
        SetName("Intake");
    }

void IntakeSubsystem::setFront(ControlMode mode, double mPow){
    frontMtr.Set(mode, mPow);
}

void IntakeSubsystem::setFront(double pPow){
    frontMtr.Set(ControlMode::PercentOutput, pPow);
}

void IntakeSubsystem::setRear(ControlMode mode, double mPow){
    rearMtr.Set(mode, mPow);
}

void IntakeSubsystem::setRear(double pPow){
    rearMtr.Set(ControlMode::PercentOutput, pPow);
}

double IntakeSubsystem::getFrontPow(){
    return frontMtr.GetMotorOutputPercent();
}

double IntakeSubsystem::getRearPow(){
    return rearMtr.GetMotorOutputPercent();
}

void IntakeSubsystem::raise(){
    frontSolenoid.Set(false);
    rearSolenoid.Set(false);
}

void IntakeSubsystem::raise(bool front, bool rear){
    frontSolenoid.Set(front == true ? false : frontSolenoid.Get());
    rearSolenoid.Set(rear == true ? false : rearSolenoid.Get());
}

void IntakeSubsystem::lower(){
    frontSolenoid.Set(true);
    rearSolenoid.Set(true);
}

void IntakeSubsystem::lower(bool front, bool rear){
    frontSolenoid.Set(front == true ? true : frontSolenoid.Get());
    rearSolenoid.Set(rear == true ? true : rearSolenoid.Get());
}

bool IntakeSubsystem::getFrontState(){
    return frontSolenoid.Get();
}

bool IntakeSubsystem::getRearState(){
    return rearSolenoid.Get();
}