// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/AnalogInput.h>
#include <frc/DigitalInput.h>
#include <ctre/Phoenix.h>

class ClawSubsystem : public frc2::SubsystemBase {
 public:
  ClawSubsystem();

  /**
   * Set The Claw Motor Velocity
   * 
   * @param velocity CTRE Closed Loop Velocity Control Target
   */
  void set(double velocity);

  /**
   * Set The Claw Motor
   * 
   * @param mode The CTRE FX Control Mode
   * @param iPow The Motor Power
   */
  void set(ControlMode mode, double iPow);

  /**
   * @brief Set the Claw Motors Neutral Mode
   * 
   * @param neutralMode The CTRE Neutral Mode to apply to the motor
   */
  void setMode(NeutralMode neutralMode);

  /**
   * @brief Get the Claw Motors Percent Output
   * 
   * @return The Motors Percent Output [-1, 1]
   */
  double getPercentOutput();

  /**
   * @brief Get the Claw Motors Current Velocity
   * 
   * @return The Motors Current Velocity
   */
  double getVelocity();

  /**
   * @brief Get the Claw Motors Current Position
   * 
   * @return The Claw Motors Integrated Encoders Position
   */
  double getPosition();

  /**
   * @brief Reset The Claw Motor Integrated Encoder's Position
   * 
   */
  void resetPosition();

  /**
   * @brief Reset The Claw Motor Integrated Encoder's Position
   * 
   * @param zero The Motors new Home Position
   */
  void resetPosition(double zero);

  /**
   * @brief Get the Claw's Potentiometer
   * 
   * @returns The Potentiometers Value
   */
  double getPot();

  /**
   * @brief Get the Scaled Position of the Claw
   * 
   * @return The Scaled Position [0, 100], [top, bottom]
   */
  double getScaledPosition();

  /**
   * @brief Get the Claws Virtual Limit
   * 
   * @returns 
   *  -1 if the claw has reached the upper limit :
   *  0 if the claw is within bounds :
   *  1 if the claw has reached the lower limit
   */
  int getVirtualLimit();

  /**
   * @brief Get the Claws Lower Limit
   * 
   * @returns TRUE if the Limit is Pressed
   */
  bool getLowerLimit();

  /**
   * @brief Get the Claws Upper Limit
   * 
   * @returns TRUE if the Limit is Pressed
   */
  bool getUpperLimit();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  TalonFX ClawMotor;
  frc::AnalogInput Potentiometer;
  frc::DigitalInput lowerLimit;
  frc::DigitalInput upperLimit;
};
