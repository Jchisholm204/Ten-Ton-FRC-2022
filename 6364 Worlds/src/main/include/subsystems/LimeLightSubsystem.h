// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"
#include "wpi/span.h"

class LimeLightSubsystem : public frc2::SubsystemBase {
 public:
  LimeLightSubsystem();

  // Camera LED Modes
  enum LEDMode{
    noMode, off, blink, on
  };

  // Camera Operation Modes
  enum CamMode{
    vision, driveCam
  };

  /**
   * @brief Retrieve the X value of the Target
   * @returns Horizontal Offset From Crosshair To Target (-27 degrees to 27 degrees)
   */
  double getX();

  /**
   * @brief Retrieve the Y value of the Target
   * @returns Vertical Offset From Crosshair To Target (-20.5 degrees to 20.5 degrees)
   */
  double getY();

  /**
   * @brief Get if the limelight has any valid targets (0 or 1)
   * @returns TRUE if the LimeLight has a target
   */
  bool hasTarget();

  /**
   * @brief Retrieve the Area of the Target
   * @returns Target Area (0% of image to 100% of image)
   */
  double getArea();

  /**
   * @brief Sets limelight’s LED state
   */
  void setLED(LEDMode mode);

  /**
   * camMode	Sets limelight’s operation mode
   *   0	Vision processor
   *   1	Driver Camera (Increases exposure, disables vision processing)
    */
  void setMode(CamMode mode);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
};
