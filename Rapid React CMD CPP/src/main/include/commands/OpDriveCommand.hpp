#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveSubsystem.hpp"

class OpDriveCommand : public frc2::CommandHelper<frc2::CommandBase, OpDriveCommand> {
    public:
    explicit OpDriveCommand(DriveSubsystem* SubSystem_Drive);

    void Execute() override;

    void End(bool interrupted) override;

    private:
        double exponential(double joystickVal, float driveExp, double joydead, int motorMin);
        DriveSubsystem* drive;
};