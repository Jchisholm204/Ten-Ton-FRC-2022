#pragma once

/**
 * @file OpDrive.hpp
 * @author Jacob Chisholm
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * @brief Simple Operator Drive using Exponential and Closed Loop Velocity Control
 * 
 */

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveSubsystem.hpp"

/**
 * @brief DriveCommands Namespace
 * 
 * Acts as a group for all of the commands that interact with mainly the drivebase
 */
namespace DriveCommands
{
    class OpDrive : public frc2::CommandHelper<frc2::CommandBase, OpDrive> {
        public:
        explicit OpDrive(DriveSubsystem* SubSystem_Drive);

        void Execute() override;

        void End(bool interrupted) override;

        private:
            DriveSubsystem* drive;
};
} // namespace DriveCommands