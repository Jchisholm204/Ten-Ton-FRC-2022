// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>

#include "RobotContainer.h"
#include <rev/CANSparkMax.h>
#include <frc/XboxController.h>
#include <frc/AnalogInput.h>
#include <frc/DigitalInput.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc2::Command* m_autonomousCommand = nullptr;

  RobotContainer m_container;

  rev::CANSparkMax leftDrive{0, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax rightDrive{1, rev::CANSparkMaxLowLevel::MotorType::kBrushless};

  frc::AnalogInput throttle{0};
  frc::AnalogInput steering{1};
  frc::DigitalInput brake{0};
};
