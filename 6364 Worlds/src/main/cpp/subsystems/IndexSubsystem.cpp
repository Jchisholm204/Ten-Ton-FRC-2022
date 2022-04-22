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
 *    - Top and Bottom Photoelectric Sensors
 *    - Color Sensor Mounted at the base of the Index
 *    - Color Sensor Mounted near the Top Indexer
 *    - Toggle Switch Inside the Electronics Board used to select team color
 *
 *  Default Command:
 *    - Automatic Ball Indexing with Photoelectric and Color Sensors
 *    
 */

#include "subsystems/IndexSubsystem.hpp"
#include "Constants.h"
#include "tools/Motors.hpp"
#include <frc/I2C.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "RobotContainer.h"

IndexSubsystem::IndexSubsystem() :
    //topMtr{RobotMap::CAN::TopIndex, rev::CANSparkMaxLowLevel::MotorType::kBrushless},
    topMtr{RobotMap::CAN::TopIndex},
    botMtr{RobotMap::CAN::BottomIndex},
    feedMtr{RobotMap::CAN::FeedIndex},
    feedPE{RobotMap::DIGITAL::Index_PE_feed},
    topColor{frc::I2C::kMXP}
    {
        motorConfiguration::Talon::index(botMtr, false);
        motorConfiguration::Talon::index(feedMtr, true);
        motorConfiguration::Talon::index(topMtr, true);
        //topColor.ConfigureColorSensor(rev::ColorSensorV3::ColorResolution::k20bit, rev::ColorSensorV3::ColorMeasurementRate::k25ms);
        SetName("Index");
    }

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

bool IndexSubsystem::getTopIR(){ // Top IR Located on Rio XMP I2C port
    return (topColor.GetProximity()-40) > kIndex::k_colorProxTrigger;
}

bool IndexSubsystem::getBotIR(){ // Bot IR Located on Raspberry Pi I2C port
    //Get Current reading from Pi through NetworkTables
    return nt::NetworkTableInstance::GetDefault().GetTable("rpi")->GetNumber("proximity1", -1) > kIndex::k_colorProxTrigger;
}

bool IndexSubsystem::getFeedPE(){
    return feedPE.Get();
}
/*
IndexSubsystem::TeamColors IndexSubsystem::getTeam(){
    if(teamSwitch.Get()){
        return TeamColors::blue;
    }
    else{
        return TeamColors::red;
    }
}*/

bool IndexSubsystem::getRedBall(){
    return topColor.GetColor().red > kIndex::redMinimum && topColor.GetColor().blue < kIndex::blueMaximum;
}

bool IndexSubsystem::getBlueBall(){
    return topColor.GetColor().blue > kIndex::blueMinimum && topColor.GetColor().red < kIndex::redMaximum;
}

IndexSubsystem::TeamColors IndexSubsystem::getTopBallColor(){
    if(topColor.GetColor().blue > kIndex::blueMinimum && topColor.GetColor().red < kIndex::redMaximum){
        return TeamColors::blue;
    }
    else if(topColor.GetColor().red > kIndex::redMinimum && topColor.GetColor().blue < kIndex::blueMaximum){
        return TeamColors::red;
    }
    else{
        return TeamColors::null;
    }
}

IndexSubsystem::TeamColors IndexSubsystem::getBottomBallColor(){
    double defaultVals[] = {0, 0, 0};
    std::vector<double> botColor = nt::NetworkTableInstance().GetDefault().GetTable("rpi")->GetNumberArray("color1", defaultVals);
    if(botColor[2] > kIndex::blueMinimum && botColor[0] < kIndex::redMaximum){
        return TeamColors::blue;
    }
    else if(botColor[0] > kIndex::redMinimum && botColor[2] < kIndex::blueMaximum){
        return TeamColors::red;
    }
    else{
        return TeamColors::null;
    }
}

void IndexSubsystem::Periodic(){
    frc::SmartDashboard::PutBoolean("Top IR", getTopIR());
    frc::SmartDashboard::PutBoolean("Bottom IR", getBotIR());
    frc::SmartDashboard::PutBoolean("Feed PE", getFeedPE());
    //Bottom Color no longer attached to roborio
    //frc::SmartDashboard::PutNumber("Bot Proxim", bottomColor.GetProximity());
    frc::SmartDashboard::PutNumber("Top Proxim", topColor.GetProximity()-40);
    frc::SmartDashboard::PutNumber("Top Indx RPM", c_TalonRPM(getTopVelocity()));
    frc::SmartDashboard::PutNumber("Top AMPS", topMtr.GetSupplyCurrent());
    
    if(getTopBallColor() == TeamColors::blue){
        frc::SmartDashboard::PutString("Top Ball Color", "Blue");
    }
    else if(getTopBallColor() == TeamColors::red){
        frc::SmartDashboard::PutString("Top Ball Color", "Red");
    }
    else{
        frc::SmartDashboard::PutString("Top Ball Color", "Unknown");
    }

    if(getBottomBallColor() == TeamColors::blue){
        frc::SmartDashboard::PutString("Bottom Ball Color", "Blue");
    }
    else if(getBottomBallColor() == TeamColors::red){
        frc::SmartDashboard::PutString("Bottom Ball Color", "Red");
    }
    else{
        frc::SmartDashboard::PutString("Bottom Ball Color", "Unknown");
    }
    frc::SmartDashboard::PutNumber("R", topColor.GetColor().red);
    frc::SmartDashboard::PutNumber("G", topColor.GetColor().green);
    frc::SmartDashboard::PutNumber("B", topColor.GetColor().blue);
/*
    double defaultVals[] = {0, 0, 0};
    std::vector<double> botColor = nt::NetworkTableInstance().GetDefault().GetTable("rpi")->GetNumberArray("color1", defaultVals);

    frc::SmartDashboard::PutNumber("R", botColor[0]);
    frc::SmartDashboard::PutNumber("G", botColor[1]);
    frc::SmartDashboard::PutNumber("B", botColor[2]);
*/
    //printf("R: %f \t G: %f \t B: %f \n", topColor.GetColor().red, topColor.GetColor().green, topColor.GetColor().blue);
}