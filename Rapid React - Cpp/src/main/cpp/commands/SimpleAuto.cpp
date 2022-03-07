// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SimpleAuto.h"
#include "subsystems/IndexSubsystem.hpp"
#include "subsystems/DriveSubsystem.hpp"
#include "subsystems/IntakeSubsystem.hpp"

SimpleAuto::SimpleAuto(IndexSubsystem* indx, DriveSubsystem *drve, IntakeSubsystem *intke) : index{indx}, drive{drve}, intake{intke} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(index);
  AddRequirements(drive);
  AddRequirements(intake);
}

// Called when the command is initially scheduled.
void SimpleAuto::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void SimpleAuto::Execute() {
    drive->resetDrive();
    index->shoot(1);
    frc::Wait(units::second_t{1});
    index->stop();
    index->setFeed(ControlMode::PercentOutput, 1);
    index->setBot(ControlMode::PercentOutput, 0.4);
    intake->lower(false, true);
    intake->setRear(ControlMode::PercentOutput, 1);
    drive->set(ControlMode::MotionMagic, -243200, -243200);
    frc::Wait(units::second_t{4});
    drive->set(ControlMode::MotionMagic, 4816, 4816);
    frc::Wait(units::second_t{4});
    index->shoot(1);
    frc::Wait(units::second_t{4});
}

// Called once the command ends or is interrupted.
void SimpleAuto::End(bool interrupted) {
  index->stop();
  intake->setRear(ControlMode::PercentOutput, 0);
  intake->raise(true, true);
}

// Returns true when the command should end.
bool SimpleAuto::IsFinished() {
  return true;
}
