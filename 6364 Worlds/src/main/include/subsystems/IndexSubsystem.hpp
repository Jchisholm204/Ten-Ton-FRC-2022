/**
 * Index Subsystem
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * Intake Subsystem:
 *    - 3 Index Motors
 *    - Feed and Bottom Index Powered by Vex Pro 775 and Talon SRX
 *    - Top Index Powered by NEO and Spark Max
 *    - Top and Bottom Photoelectric Sensors
 *    - Color Sensor Mounted at the base of the Index
 *
 *    - Automatic Ball Indexing with Photoelectric and Color Sensors
 *    
 */

#pragma once
#include "Constants.h"

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>

// Macro For Spark Max Control Type
#define SPCT rev::CANSparkMax::ControlType

class IndexSubsystem : public frc2::SubsystemBase {
 public:
  IndexSubsystem();

  /**
   * Set The Top Indexer's Percent Output
   * @param percentOutput The Spark Max Percent Output [-1.0, 1.0]
   */
  void setTop(double percentOutput);

  /**
   * Control the Top Indexer's Motor Controller
   * @param mode The REV Spark Max Motor Control Mode
   * @param iPow The Applied Power
   */
  void setTop(SPCT mode, double iPow);

  /**
   * Get The Top Indexers Percent Output
   * @returns The Percent Output [-1.0, 1.0]
   */
  double getTopOutput();

  /**
   * Set The Bottom Indexer's Percent Output
   * @param percentOutput The CTRE Percent Output [-1.0, 1.0]
   */
  void setBottom(double percentOutput);

  /**
   * Control the Bottom Indexer's Motor Controller
   * @param mode The CTRE Motor Control Mode
   * @param iPow The Applied Power
   */
  void setBottom(ControlMode mode, double iPow);

  /**
   * Get The Bottom Indexers Percent Output
   * @returns The Percent Output [-1.0, 1.0]
   */
  double getBotOutput();

  /**
   * Set The Feed Indexer's Percent Output
   * @param percentOutput The CTRE Percent Output [-1.0 , 1.0]
   */
  void setFeed(double percentOutput);

  /**
   * Control the Feed Indexer's Motor Controller
   * @param mode The CTRE Motor Control Mode
   * @param iPow The Applied Power
   */
  void setFeed(ControlMode mode, double iPow);

  /**
   * Get The Bottom Indexers Percent Output
   * @returns The Percent Output [-1.0, 1.0]
   */
  double getFeedOutput();

  /** Get if the Top Photoelectric Sensor is currently Triggered
   * @returns TRUE if the sensor is triggered
   */
  bool getTopPE();

  /** Get if the Bottom Photoelectric Sensor is currently Triggered
   * @returns TRUE if the sensor is triggered
   */
  bool getBotPE();

 private:
  rev::CANSparkMax topMtr;
  TalonSRX botMtr;
  TalonSRX feedMtr;

  frc::DigitalInput topPE;
  frc::DigitalInput bottomPE; 

  rev::SparkMaxPIDController topMtrPID;
  
};
