/**
 * Drive Subsystem
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * Drive Subsystem:
 *    - 4 Falcon FX 500 Motors
 *    - Master and Slave configuration
 *    - Exponential Controller with Deadband
 *    - NavX Gyro
 *    
 */

#pragma once
#include "Constants.h"

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <AHRS.h>

/**
 * Drive Subsystem
 * 
 * Provides an interface to the Drive Motors as well as the AHRS
 * 
 * AHRS is the robots Altitude and Heading Reference System
 * Connecting to the Robot through the XMP port, it provides
 * the robot with real time Positional and Heading Data
 */

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

    /**
     * Set the Drive Power
     * @param mode The CTRE Control Mode
     * @param leftPow The power applied to the left side of the drivebase
     * @param rightPow The power applied to the right side of the drivebase
     */
  void set(ControlMode mode, double leftPow, double rightPow);

    /**
     * CTRE Closed Loop Velocity Control
     * @param leftPow The Left Side Velocity (encoder units per 100ms)
     * @param rightPow The Right Side Velocity (encoder units per 100ms)
     */
  void set(double leftPow, double rightPow);
  /**
   * Set the Drive Power
   * @param mode The CTRE Control Mode
   * @param iPow The Power to be applied to all drive motors
   */
  void set(ControlMode mode, double iPow);

  /**
   * Set The Drive Velocity
   * @param velocity The UPR/100ms to use with the CTRE Closed Loop Velocity Control
   */
  void set(double velocity);

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

  /**
   * Get the Selected Sensor Position for the Right Drive
   * @return The TalonFX's Integrates Sensors current position
   */
  double getRightPos();

  /**
   * Get the Selected Sensor Position for the Left Drive
   * @return The TalonFX's Integrates Sensors current position
   */
  double getLeftPos();

  /**
   * Get The Drive's Position in encoder Units
   * @returns The Average of the Left and Right Drive positions
   */
  double getPos();

  //Reset The DriveBase Encoders
  void resetDrive();

  /**
   * Get The Rotation from the NavX
   * @return The Current Rotation in Degrees
   */
  double getRotation();

  //Reset The NavX Yaw (rotation) Axis
  void resetNav();

  void calibrateNav();

  //Robot Drive Directions (for naxX Displacement)
  enum Direction{
    X, Y, Z
  };

  /**
   * Returns the displacement (in meters) of the d axis since resetDisplacement() was last invoked [Experimental].
   *
   * @param d The Axis to Return Direction for
   * 
   * @return Displacement of the Axis since last reset (in meters).
   */
  float getNavPos(Direction d);

  //Calls ResetDisplacement()
  void resetNavPos();

 private:
  TalonFX driveRM;
  TalonFX driveRS;
  TalonFX driveLM;
  TalonFX driveLS;

  AHRS navX;
};
