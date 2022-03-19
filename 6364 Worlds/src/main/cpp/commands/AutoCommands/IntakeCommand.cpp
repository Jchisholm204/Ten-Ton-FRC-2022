// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoCommands/IntakeCommand.hpp"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
AutoCommands::IntakeCommand::IntakeCommand(IntakeSubsystem* IntakeSubsystem, bool on, bool front, bool rear) : intake{IntakeSubsystem}, running{on}, f{front}, r{rear} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(intake);
}
AutoCommands::IntakeCommand::IntakeCommand(IntakeSubsystem* IntakeSubsystem, bool on) : intake{IntakeSubsystem}, running{on}, f{true}, r{true} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(intake);
}

// Called when the command is initially scheduled.
void AutoCommands::IntakeCommand::Initialize() {
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
