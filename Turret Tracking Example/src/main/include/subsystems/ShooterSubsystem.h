// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include "Constants.h"

class ShooterSubsystem : public frc2::SubsystemBase {
 public:
  ShooterSubsystem();

  /**
   * @brief Get if the LimeLight is locked on a target
   * @returns  -5_deg < Target < 5_deg
   */
  bool TargetLock();

  /**
   * @brief Control the Fly Wheel Motor
   * 
   * @param mode CTRE Control Mode
   * @param power CTRE Control Power
   */
  void setFlyWheel(ControlMode mode, double power);

  /**
   * @brief Control the Fly Wheel Motor
   * 
   * @param velocity CTRE Closed Loop Velocity Control
   */
  void setFlyWheel(double velocity);

  /**
   * @brief Set the Back Spin Motor
   * 
   * @param mode CTRE Control Mode
   * @param power CTRE Control Power
   */
  void setBackSpin(ControlMode mode, double power);

  /**
   * @brief Control the BackSpin Motor
   * 
   * @param velocity CTRE Closed Loop Velocity Control
   */
  void setBackSpin(double velocity);

  /**
   * @brief Set the FW Feed Motor
   * 
   * @param mode CTRE Control Mode
   * @param power CTRE Control Power
   */
  void setFeed(ControlMode mode, double power);

  /**
   * @brief Control the Feed Motor
   * 
   * @param velocity CTRE Percent Output
   */
  void setFeed(double percentOutput);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  TalonFX flywheelMotor{RobotMap::CAN::FlyWheelMotor};
  TalonFX backspinMotor{RobotMap::CAN::BackSpinMotor};
  TalonSRX feedMotor{RobotMap::CAN::FWFeedMotor};
};
