#pragma once

// Include All Commands

// Drive Commands
#include "commands/DriveCommands/OpDrive.hpp"
#include "commands/DriveCommands/DriveTurn.hpp"
#include "commands/DriveCommands/DriveDist.hpp"

// Intake Commands
#include "commands/IntakeCommands/OpIntake.hpp"
#include "commands/IntakeCommands/Intake.hpp"

// Index Commands
#include "commands/IndexCommands/Index.hpp"
#include "commands/IndexCommands/ShootLow.hpp"
#include "commands/IndexCommands/BackFeed.hpp"
#include "commands/IndexCommands/ShootHigh.hpp"
#include "commands/IndexCommands/Stop.hpp"
#include "commands/IndexCommands/Manual.hpp"

// Auton Commands
#include "commands/AutonCommand.hpp"

// Winch Commands
#include "commands/HangCommands/WinchDown.hpp"
#include "commands/HangCommands/LowerRobot.hpp"
#include "commands/HangCommands/PneumaticControl.hpp"

// Claw Commands
#include "commands/HangCommands/ClawUp.hpp"
#include "commands/HangCommands/ClawDown.hpp"