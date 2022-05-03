// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

class TurretSubsystem : public frc2::SubsystemBase {
 public:
  TurretSubsystem();

  /**
   * @brief Manually Drive the Turret Motor
   * 
   * @param mode CTRE ControlMode
   * @param power CTRE ControlMode Power
   */
  void drive(ControlMode mode, double power);

  /**
   * @brief Rotate the Turret With Degree Measurements
   * 
   * @param degVel The Deg/Sec to move the Turret
   */
  void setVel(double degVel);

  /**
   * @brief Set The Turret's Heading
   * 
   * @param deg Deg heading
   */
  void set(double deg);

  /**
   * @brief Set The Turret's Heading
   * 
   * @param deg Radian heading
   */
  void setRads(double rads);

  /**
   * @brief Get The Turrets Current Heading
   * 
   * @return The Turrets Heading In Degrees
   */
  double get();

  /**
   * @brief Get The Turrets Current Heading
   * 
   * @return The Turrets Heading In Radians
   */
  double getRads();

  void Periodic() override;

 private:
  TalonSRX TurretMotor{1};
  void ConfigTurretMotor();
};
