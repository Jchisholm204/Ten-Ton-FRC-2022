/**
 * Index Subsystem
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * Intake Subsystem:
 *    - 3 Index Motors
 *    - Feed and Bottom Index Powered by Vex Pro 775 and Talon SRX
 *    - Top Index Powered by Falcon 500 and Integrated TalonFX
 *    - Photoelectric Sensor Mounted within the Electronics board on the feed indexer
 *    - Color Sensors mounted near the Top and Bottom Indexers
 *    - SmartDashboard Sendable Chooser used to change TeamColor
 *        - Setting TeamColor to none (null) Disables Color Sorting
 *        - More Information within Indexing Commands
 *
 *  Default Command:
 *    - Automatic Ball Indexing with Photoelectric and Color Sensors
 *    
 */

#pragma once
#include "Constants.h"

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>
#include <ctre/Phoenix.h>
#include "rev/ColorSensorV3.h"
#include "networktables/NetworkTableInstance.h"


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

  /** Get if the Top Color Sensor's IR Object Detection is currently Triggered
   * @returns TRUE if the sensor is detecting an object
   */
  bool getTopIR();

  /** Get if the Top Color Sensor's IR Object Detection is currently Triggered
   * @returns TRUE if the sensor is triggered
   */
  bool getBotIR();

  /**
   * Get If The PhotoElectric Sensor on the Feed Indexer is Currently Detecting a Ball
   * @returns TRUE if the Sensor is detecting a ball
   */
  bool getFeedPE();

  enum TeamColors{
    red = 1, blue = 2, null = 3
  };
  

  /**
   * @brief Get The Team Color Selected by the Two Way Toggle Switch in the Electronics Board
   * @returns Team red or blue
   */
  //TeamColors getTeam();

  /**
   * @brief Get if the color sensor is detecting a red ball
   * 
   * @return TRUE if the color sensor detects a red ball
   */
  bool getRedBall();

  /**
   * @brief Get if the color sensor is detecting a blue ball
   * 
   * @return TRUE if the color sensor detects a blue ball
   */
  bool getBlueBall();

  /**
   * @brief Get the Top Ball Color
   * 
   * @returns A TeamColor, TeamColors::null if no ball is detected
   */
  TeamColors getTopBallColor();

  /**
   * @brief Get the Bottom Ball Color
   * 
   * @returns A TeamColor, TeamColors::null if no ball is detected
   */
  TeamColors getBottomBallColor();


  void Periodic() override;


 private:
  TalonFX topMtr;
  TalonSRX botMtr;
  TalonSRX feedMtr;

  frc::DigitalInput feedPE;

  rev::ColorSensorV3 topColor;
  
};
