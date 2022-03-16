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
#include "Motors.hpp"

IndexSubsystem::IndexSubsystem() :
    topMtr{RobotMap::CAN::TopIndex, rev::CANSparkMaxLowLevel::MotorType::kBrushless},
    botMtr{RobotMap::CAN::BottomIndex},
    feedMtr{RobotMap::CAN::FeedIndex},
    topPE{RobotMap::DIGITAL::Index_PE_top},
    bottomPE{RobotMap::DIGITAL::Index_PE_bottom},
    topMtrPID{topMtr.GetPIDController()}
    {
        TalonConfiguration::index(botMtr, false);
        TalonConfiguration::index(feedMtr, false);
        SparkConfiguration::index(topMtrPID, topMtr, false);
    }


void IndexSubsystem::setTop(double percentOutput){
    topMtrPID.SetReference(percentOutput, SPCT::kDutyCycle);
}

void IndexSubsystem::setTop(SPCT mode, double iPow){
    topMtrPID.SetReference(iPow, mode);
}

double IndexSubsystem::getTopOutput(){
    return topMtr.Get();
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