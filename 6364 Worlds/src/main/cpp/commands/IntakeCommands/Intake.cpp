// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IntakeCommands/Intake.hpp"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
IntakeCommands::Intake::Intake(IntakeSubsystem* IntakeSubsystem, bool on, bool front, bool rear) : intake{IntakeSubsystem}, running{on}, f{front}, r{rear} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(intake);
  SetName("Intake");
}
IntakeCommands::Intake::Intake(IntakeSubsystem* IntakeSubsystem, bool on) : intake{IntakeSubsystem}, running{on}, f{true}, r{true} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(intake);
  SetName("Intake");
}

// Called when the command is initially scheduled.
void IntakeCommands::Intake::Initialize() {
  if(running){
    intake->lower(f, r);
    if(f){
      intake->setFront(1);
    }
    if(r){
      intake->setRear(1);
    }
  }
  else{
    intake->raise(f, r);
    if(f){
      intake->setFront(0);
    }
    if(r){
      intake->setRear(0);
    }
  }
}
