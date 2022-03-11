/**
 * Intake Subsystem
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * Intake Subsystem:
 *    - Front and Rear Intakes
 *    - 2 Bag Motors controlled by CTRE Talon SRX
 *    - 2 double action solenoids (one for front / one for rear)
 *    
 */

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PneumaticHub.h>
#include <frc/PneumaticsControlModule.h>
#include <frc/Solenoid.h>
#include <ctre/Phoenix.h>

class IntakeSubsystem : public frc2::SubsystemBase {
 public:
  IntakeSubsystem();

  /**
   * Set The Front Intake Motor
   * 
   * @param mode The CTRE SRX Control Mode
   * @param mPow The Motor Power
   */
  void setFront(ControlMode mode, double mPow);

  /**
   * Set The Front Intake Motor
   * 
   * @param pPow The Motor Power (Percent Output) [-1, 1]
   */
  void setFront(double pPow);

  /**
   * Set The Rear Intake Motor
   * 
   * @param mode The CTRE SRX Control Mode
   * @param mPow The Motor Power
   */
  void setRear(ControlMode mode, double mPow);

  /**
   * Set The Rear Intake Motor
   * 
   * @param pPow The Motor Power (Percent Output) [-1, 1]
   */
  void setRear(double mPow);

  /**
   * Get The Current Moto rPower Applied to the Front Intake
   * 
   * @return [-1, 1]
   */
  double getFrontPow();

  /**
   * Get The Current Motor Power Applied to the Rear Intake
   * 
   * @return [-1, 1]
   */
  double getRearPow();

  // Raise Both Intakes (using the solenoids)
  void raise();

  /**
   * Raise One Or Both of the Intakes (using the solenoids)
   * 
   * @param front TRUE to raise the Front Intake
   * @param rear TRUE to raise the Rear Intake
   */
  void raise(bool front, bool rear);

  // Lower Both Intakes (using the solenoids)
  void lower();

  /**
   * Lower One or Both of the Intakes (using the solenoids)
   * 
   * @param front TRUE to Lower the Front Intake
   * @param rear TRUE to Lower the Rear Intake
   */
  void lower(bool front, bool rear);

  /** @return TRUE if the Front Intake is currently DOWN */
  bool getFrontState();

  /** @return TRUE if the Rear Intake is currently DOWN */
  bool getRearState();

 private:
  TalonSRX frontMrt;
  TalonSRX rearMtr;
};
