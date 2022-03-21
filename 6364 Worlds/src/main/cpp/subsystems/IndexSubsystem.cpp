/**
 * Index Subsystem
 * 
 * @link IndexSubsystem.hpp
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

#include "subsystems/IndexSubsystem.hpp"
#include "Constants.h"
#include "tools/Motors.hpp"
#include <frc/I2C.h>

IndexSubsystem::IndexSubsystem() :
    //topMtr{RobotMap::CAN::TopIndex, rev::CANSparkMaxLowLevel::MotorType::kBrushless},
    topMtr{RobotMap::CAN::TopIndex},
    botMtr{RobotMap::CAN::BottomIndex},
    feedMtr{RobotMap::CAN::FeedIndex},
    topPE{RobotMap::DIGITAL::Index_PE_top},
    bottomPE{RobotMap::DIGITAL::Index_PE_bottom},
    //topMtrPID{topMtr.GetPIDController()}
    feedColor{frc::I2C::kOnboard}
    {
        motorConfiguration::Talon::index(botMtr, false);
        motorConfiguration::Talon::index(feedMtr, false);
        motorConfiguration::Talon::index(topMtr, false);
        //motorConfiguration::SparkMax::index(topMtrPID, topMtr, false);
    }

/*  SPARK MAX
void IndexSubsystem::setTop(double percentOutput){
    topMtrPID.SetReference(percentOutput, SPCT::kDutyCycle);
}

void IndexSubsystem::setTop(SPCT mode, double iPow){
    topMtrPID.SetReference(iPow, mode);
}

double IndexSubsystem::getTopOutput(){
    return topMtr.Get();
}
*/

void IndexSubsystem::setTop(double percentOutput){
    topMtr.Set(ControlMode::PercentOutput, percentOutput);
}

void IndexSubsystem::setTop(ControlMode mode, double iPow){
    topMtr.Set(mode, iPow);
}

void IndexSubsystem::setTopVel(double velocity){
    topMtr.Set(ControlMode::Velocity, velocity);
}

double IndexSubsystem::getTopOutput(){
    return topMtr.GetMotorOutputPercent();
}

double IndexSubsystem::getTopVelocity(){
    return topMtr.GetSelectedSensorVelocity();
}

void IndexSubsystem::setBottom(double percentOutput){
    botMtr.Set(ControlMode::PercentOutput, percentOutput);
}

void IndexSubsystem::setBottom(ControlMode mode, double iPow){
    botMtr.Set(mode, iPow);
}

double IndexSubsystem::getBotOutput(){
    return botMtr.GetMotorOutputPercent();
}

void IndexSubsystem::setFeed(double percentOutput){
    feedMtr.Set(ControlMode::PercentOutput, percentOutput);
}

void IndexSubsystem::setFeed(ControlMode mode, double iPow){
    feedMtr.Set(mode, iPow);
}

double IndexSubsystem::getFeedOutput(){
    return feedMtr.GetMotorOutputPercent();
}

bool IndexSubsystem::getTopPE(){
    return topPE.Get();
}

bool IndexSubsystem::getBotPE(){
    return bottomPE.Get();
}

double IndexSubsystem::getFeedProximity(){
    return feedColor.GetProximity();
}

bool IndexSubsystem::getFeedBall(){
    return feedColor.GetProximity() > kIndex::k_colorProxTrigger;
}