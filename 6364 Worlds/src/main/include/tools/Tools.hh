/**
 * FRC C++ ToolKit
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * FRC Toolkit:
 */
#pragma once

#include <stdint.h>

/**
 * FRC C++ ToolKit
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 * FRC Toolkit:
 */
namespace frcTools{

    // Interfaces for Time
    class Time{
        public:
            /**
             * Get The Current running time of the FPGA in MicroSeconds
             * @returns frc::RobotController::GetFPGATime()
             */
            static uint64_t Micros();

            /**
             * Get The Current Running Time of the FPGA In MilliSeconds
             * @returns The Running Time In MilliSeconds with MicroSecond Accuracy
             */
            static uint64_t Millis();

            /**
             * Get The Current Running Time of the FPGA In Seconds
             * @returns The Running Time In Seconds with MicroSecond Accuracy
             */
            static uint64_t Seconds();
    };
} //end FRCTools