// Constants.h
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/** Constants.h
 * @author Jchisholm204
 * 
 * @brief Constants.h
 * Used to Store Various Information about the robot and its mechanisms
 * Everything within this file is a constant, 
 * meaning it is unchanged throughought the programs runtime.
 * 
 * @namespace RobotMap - Stores all of the CAN id's, Sensor Ports, PCM ports, and Controller Ports on the { @link } driverstation
 * 
 * @namespace indexConstants - Stores Constants for the Index System
 * 
 * @namespace auton_s - Stores all of the Numerical constants for ReRun Autos
 * 
 */

#pragma once

#include <units/time.h>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */


/**
 * RobotMap:
 * Stores All of the Physical Ports for Motors, Sensors ...ex
 */
namespace RobotMap {

    // CAN ID's
    namespace CAN {

        constexpr int Intake_front = 9;
        constexpr int Intake_rear = 6;

        constexpr int driveRM = 4;
        constexpr int driveRS = 5;
        constexpr int driveLM = 2;
        constexpr int driveLS = 3;

        constexpr int TopIndex = 1;
        constexpr int BottomIndex = 7;
        constexpr int FeedIndex = 8;

        constexpr int WinchMtr = 10;
        constexpr int ClawMtr = 11;

        constexpr int PDP = 0;

    }//End CAN

    // Analog Devices Port IDs
    namespace ANALOG {
        constexpr int topPE = 0;
        constexpr int botPE = 1;
    }//End Analog

    // Digital Devices Port IDs
    namespace DIGITAL {
        constexpr int Claw_Limit_UPPER = 9;
        constexpr int Claw_Limit_LOWER = 8;
        constexpr int Hang_Limit_LOWER = 7;
    }//End Digital

    // PCM Controller IDs
    namespace PCM {

        constexpr int frontIntake = 0;
        constexpr int rearIntake = 1;
        constexpr int armPiston = 2;

    }//End PCM

    // DriverStation IDs
    namespace DriverStation {

        constexpr int masterController = 0;
        constexpr int partnerController = 1;

    }//End DriverStation
}//End RobotMap


// Stores Indexer Constants:
// ShootTime, Status..
namespace kIndex {

    // The Time Delay When Shooting to balls from the Indexers
    constexpr units::time::second_t k_shootTime{2};
    
    // The Index's Current Status
    // Used Primarily for ReRun purposes, but also for partner disable
    namespace status{
        constexpr int OFF = 0;
        constexpr int RUNNING = 1;
        constexpr int SHOOT = 2;
        constexpr int SHOT = 3;
    }//End status

}//End kIndex

// Autons Available to be Selected through SmartDashboard
// Otherwise known as Linker
namespace auton_s {
    // No Auto // Empty
    constexpr int NoAuto = 0;
    // No Auto // Empty
    constexpr int Empty = NoAuto;

    /** - TEST AUTO - 
    * Use for testing ONLY
    * Test Files may be renamed through FTP with the 
    * Rio in order to be turned into a match auto
    */
    constexpr int Test = 1;

    // Left 1 Auton Slot
    constexpr int Left1 = 2;
    // Left 2 Auton Slot
    constexpr int Left2 = 3;
    // Right 1 Auton Slot
    constexpr int Right1 = 4;
    // Right 2 Auton Slot
    constexpr int Right2 = 5;

}//End auton_s

//Macro to convert Talon FX encoder Units Per Rotation (UPR) into Rotations Per Minute (RPM)
#define c_TalonRPM(upr) (upr*600/2408)
#define c_TalonUPR(rpm) (rpm*2408/600)