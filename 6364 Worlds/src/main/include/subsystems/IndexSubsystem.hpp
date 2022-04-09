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
#include <frc/DigitalGlitchFilter.h>
#include <ctre/Phoenix.h>
#include "rev/ColorSensorV3.h"

// Macro For Spark Max Control Type
//#define SPCT rev::CANSparkMax::ControlType

class IndexSubsystem : public frc2::SubsystemBase {
 public:
  IndexSubsystem();

  /**
   * Set The Top Indexer's Percent Output
   * @param percentOutput The CTRE Percent Output [-1.0, 1.0]
   */
  void setTop(double percentOutput);

    /**
   * Set The Top Indexer's Velocity Target
   * @param percentOutput The CTRE Velocity
   */
  void setTopVel(double velocity);

  /**
   * Control the Top Indexer's Motor Controller
   * @param mode The CTRE Motor Control Mode
   * @param iPow The Applied Power
   */
  void setTop(ControlMode mode, double iPow);
  //void setTop(SPCT mode, double iPow);

  /**
   * Get The Top Indexers Percent Output
   * @returns The Percent Output [-1.0, 1.0]
   */
  double getTopOutput();

  /**
   * Get The Top Indexers Velocity
   * @returns The Motors Current Velocity in UPR
   */
  double getTopVelocity();

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

  /**
   * Get The Current Proximity reading of the Feed Indexers Color Sensor
   * @returns The Sensors Current Proximity Value
   */
  double getFeedProximity();

  /**
   * Get If The Color Sensor on the Feed Indexer is Currently Detecting a Ball
   * @returns TRUE if the Sensor is detecting a ball
   */
  bool getFeedBall();

  /**
   * @brief Get The Team Color Selected by the Two Way Toggle Switch in the Electronics Board
   * @returns TRUE for the blue team, FALSE for the red team
   */
  bool getColorSelector();

  bool getRedBall();

  bool getBlueBall();


  void Periodic() override;


 private:
  //rev::CANSparkMax topMtr;
  TalonFX topMtr;
  TalonSRX botMtr;
  TalonSRX feedMtr;

  frc::DigitalInput topPE;
  frc::DigitalInput bottomPE; 

  frc::DigitalInput teamSwitch;

  rev::ColorSensorV3 topColor;

  rev::ColorSensorV3 feedColor;

  //rev::SparkMaxPIDController topMtrPID;
  
};
