// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <AHRS.h>
#include <frc/SPI.h>

class NavXSubsystem : public frc2::SubsystemBase {
 public:
  NavXSubsystem();

  /**
   * @brief Get the Current Yaw Measurement
   * 
   * @returns The Current Yaw Measurement since the last reset 
   */
  double getYaw();

  /**
   * @brief Get the Yaw Velocity Measurement
   * 
   * @return Yaw Velocity in Deg/Sec 
   */
  double getYawVelocity();

  /**
   * @brief Calibrate the NavX Sensor
   * 
   */
  void calibrate();

  /**
   * @brief Reset the NavX's Yaw Measurement
   * 
   */
  void reset();

  /**
   * @brief Get the Current Yaw Measurement
   * 
   * @returns The Current Yaw Measurement since the last reset in Radians
   */
  double getYawRadians();

  /**
   * @brief Get the Yaw Velocity Measurement
   * 
   * @return Yaw Velocity in Rads/Sec 
   */
  double getYawVelocityRadians();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  AHRS sensor1{frc::SPI::kMXP};
  double lastYaw;

};
