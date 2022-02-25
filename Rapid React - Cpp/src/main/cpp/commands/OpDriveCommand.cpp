#include "commands/OpDriveCommand.hpp"
#include "RobotContainer.h"
#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"

OpDriveCommand::OpDriveCommand(DriveSubsystem* SubSystem_Drive) : drive{SubSystem_Drive}{
    AddRequirements(drive);
}

void OpDriveCommand::Execute(){
    /** NOTE:
     * Exponential Drive Variables should be changed within the Talon.cpp configuration file for the iLeft and iRight Motors
     * SmartDashboard is an unnessasary debugging tool, the lines referencing may be commented out
     * drive->arcadeDrive uses ControlMode::Velocity by default
     */
    double Ypow = master.GetLeftY()*21000;
    double Xpow = master.GetRightX()*21000;
    frc::SmartDashboard::PutNumber("Drive Power", Ypow);
    frc::SmartDashboard::PutNumber("Turn Power", Xpow);
    drive->arcadeDrive(Ypow, Xpow);
}

void OpDriveCommand::End(bool interrupted){
    drive->set(ControlMode::PercentOutput, 0, 0);
}