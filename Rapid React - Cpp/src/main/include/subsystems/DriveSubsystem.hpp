// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"

class DriveSubsystem : public frc2::SubsystemBase {
 public:
 //Class Initializer
  DriveSubsystem();

    /**
     * Set the Drive Power
     * @param mode The CTRE Control Mode
     * @param leftPow The power applied to the left side of the drivebase
     * @param rightPow The power applied to the right side of the drivebase
     */
  void set(ControlMode mode, double leftPow, double rightPow);

    /**
     * Arcade Drive Function (uses CTRE Velocity Control Loop)
     * @param iPow The Drive Power
     * @param turnPow The Turning Power
     */
  void arcadeDrive(double iPow, double turnPow);

  /**
   * Get the Right Side of the DriveBase's Velocity
   * @return encoder units / 100 ms
   */
  double getRightVel();

  /**
   * Get the Left Side of the DriveBase's Velocity
   * @return encoder units / 100 ms
   */
  double getLeftVel();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  TalonFX driveRM;
  TalonFX driveRS;

  TalonFX driveLM;
  TalonFX driveLS;

};
