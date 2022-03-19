#include "tools/Tools.hh"
#include <frc/RobotController.h>

using namespace frcTools;

uint64_t frcTools::Time::Micros(){
    return (frc::RobotController::GetFPGATime());
}

uint64_t frcTools::Time::Millis(){
    return (frc::RobotController::GetFPGATime() * 1.0e-3);
}

uint64_t frcTools::Time::Seconds(){
    return (frc::RobotController::GetFPGATime() * 1.0e-6);
}