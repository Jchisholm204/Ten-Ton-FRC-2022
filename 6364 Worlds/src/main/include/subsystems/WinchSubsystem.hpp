// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>
#include <frc/Solenoid.h>
#include <ctre/Phoenix.h>

class WinchSubsystem : public frc2::SubsystemBase {
 public:
  WinchSubsystem();

  /**
   * Set The Winch Motor Velocity
   * 
   * @param velocity CTRE Closed Loop Velocity Control Target
   */
  void set(double velocity);

  /**
   * Set The Winch Motor
   * 
   * @param mode The CTRE FX Control Mode
   * @param iPow The Motor Power
   */
  void set(ControlMode mode, double iPow);

  /**
   * @brief Set the Winch Motors Neutral Mode
   * 
   * @param neutralMode The CTRE Neutral Mode to apply to the motor
   */
  void setMode(NeutralMode neutralMode);

  /**
   * @brief Get the Winch Motors Percent Output
   * 
   * @return The Motors Percent Output [-1, 1]
   */
  double getPercentOutput();

  /**
   * @brief Get the Winch Motors Current Velocity
   * 
   * @return The Motors Current Velocity
   */
  double getVelocity();

  /**
   * @brief Get the Winch Motors Current Position
   * 
   * @return The Winch Motors Integrated Encoders Position
   */
  double getPosition();

  /**
   * @brief Reset The Winch Motor Integrated Encoder's Position
   * 
   */
  void resetPosition();

  /**
   * @brief Reset The Winch Motor Integrated Encoder's Position
   * 
   * @param zero The Motors new Home Position
   */
  void resetPosition(double zero);

  /**
   * @brief Get if the Winch's Lower Limit Switch is Pressed
   * 
   * @return TRUE if the Limit is pressed
   * @return FALSE if the Limit switch is open
   */
  bool getLowerLimit();

  /**
   * @brief Set the Solenoid State
   * 
   * @param state TRUE to fire the Arm Pistons
   */
  void setSolenoid(bool state);

  /**
   * @brief Get the Solenoid's Current State
   * 
   * @returns TRUE if the Solenoid is currently active 
   */
  bool getSolenoid();

 private:
  TalonFX WinchMotor;
  frc::DigitalInput lowerLimit;
  frc::Solenoid solenoid;
};
