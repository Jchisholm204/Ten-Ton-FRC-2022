#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/IndexSubsystem.hpp"

class OpIndexCommand : public frc2::CommandHelper<frc2::CommandBase, OpIndexCommand> {
    public:
        explicit OpIndexCommand(IndexSubsystem* SubSystem_index);

        void Execute() override;

        void End(bool interrupted) override;

    private:
        IndexSubsystem* index;
        double waitSaveTime;
};