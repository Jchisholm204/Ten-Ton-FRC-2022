#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/IndexSubsystem.hpp"
#include <frc/Timer.h>

class OpIndexCommand : public frc2::CommandHelper<frc2::CommandBase, OpIndexCommand> {
    public:
        explicit OpIndexCommand(IndexSubsystem* SubSystem_index);

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

    private:
        IndexSubsystem* index;
        units::time::second_t waitSaveTime;
        units::time::second_t shootTime;
        bool status_running;

};