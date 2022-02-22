// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include <frc/AnalogInput.h>
#include <frc/Compressor.h>
#include <frc/PneumaticsControlModule.h>
#include <frc/Solenoid.h>
#include <frc/PneumaticsModuleType.h>

class IntakeSubsystem : public frc2::SubsystemBase {
 public:
 //Class Initializer
  IntakeSubsystem();

  /**
   * Set the Front Intake Motor
   * @param mode The CTRE Control Mode
   * @param mPow The Applied Motor Power
   */
  void setFront(ControlMode mode, double mPow);

  /**
   * Set the Rear Intake Motor
   * @param mode The CTRE Control Mode
   * @param mPow The Applied Motor Power
   */
  void setRear(ControlMode mode, double mPow);

  /**
   * Get The Front Intake Applied Motor Power
   * @return [-1, 1]
   */
  double getFrontPow();

  /**
   * Get The Rear Intake Applied Motor Power
   * @return [-1, 1]
   */
  double getRearPow();

  /**
   * Raise The Intakes (using the Pneumatics)
   * @param front Raise the Front Intake
   * @param rear Raise the Rear Intake
   */
  void raise(bool front, bool rear);

  /**
   * Raise The Intakes (using the Pneumatics)
   */
  void raise();

  /**
   * Lower The Intakes (using the Pneumatics)
   * @param front Lower the Front Intake
   * @param rear Lower the Rear Intake
   */
  void lower(bool front, bool rear);

  /**
   * Lower The Intakes (using the Pneumatics)
   */
  void lower();

  /**
   * Get The Front Pneumatic State
   * @return Up or Down (boolean : true=down)
   */
  bool getFrontState();

  /**
   * Get The Rear Pneumatic State
   * @return Up or Down (boolean : true=down)
   */
  bool getRearState();

  /**
   * Allow the Compressor to Maintiain Tank Pressure
   */
  void startCompressor();

  /**
   * Stop The Compressor
   */
  void stopCompressor();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  TalonSRX frontMtr;
  TalonSRX rearMtr;

  frc::Solenoid frontPiston;
  frc::Solenoid rearPiston;

  frc::Compressor compressor;

};
