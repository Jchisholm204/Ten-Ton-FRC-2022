#include "tools/Tools.hh"
#include <frc/RobotController.h>

using namespace frcTools;

int64_t frcTools::Time::Micros(){
    return (frc::RobotController::GetFPGATime());
}

int64_t frcTools::Time::Millis(){
    return (frc::RobotController::GetFPGATime() * 1.0e-3);
}

int64_t frcTools::Time::Seconds(){
    return (frc::RobotController::GetFPGATime() * 1.0e-6);
}