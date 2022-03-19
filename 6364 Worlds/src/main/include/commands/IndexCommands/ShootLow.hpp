// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/IndexSubsystem.hpp"

namespace IndexCommands{

  /**
   * Index Shoot Low Goal Command
   * 
   * @returns TRUE after shoot time has elapsed
   */
  class ShootLow
      : public frc2::CommandHelper<frc2::CommandBase, ShootLow> {
    public:
      ShootLow(IndexSubsystem* indexSubsystem);

      void Initialize() override;

      void Execute() override;

      void End(bool interrupted) override;

      bool IsFinished() override;

    private:
      IndexSubsystem* subsystem;
      bool isFinished;
      units::second_t startTime;

  };
}
