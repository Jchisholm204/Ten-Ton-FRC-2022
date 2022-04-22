/** Constants.h
 * @author Jchisholm204
 * @date 3/12/2022
 * @version 2.32
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
 * @namespace kHang - Stores all of the Constant Variables associated with the hang
 * 
 */

#pragma once

#include "units/time.h"

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
        /**
         * TODO:
         * Change all CAN ID's to reflect the devices
         * position within the code.
         * 
         * ie, a device with no sensing, or feedback loop,
         * like an intake, or the feed indexer should have a higher
         * CAN ID than a device with frequent access like a
         * master drive motor, or the winch motor
         */

        constexpr int Intake_front = 9; //changeTo ~ 8
        constexpr int Intake_rear = 6; //changeTo ~ 9

        constexpr int driveRM = 4; //changeTo ~ 1
        constexpr int driveRS = 5; //changeTo ~ 11
        constexpr int driveLM = 2; //changeTo ~ 2
        constexpr int driveLS = 3; //changeTo ~ 12

        constexpr int TopIndex = 11; //changeTo ~ 5 (Going to be a NEO motor anyways)
        constexpr int BottomIndex = 7; //changeTo ~ 6
        constexpr int FeedIndex = 8; //changeTo ~ 7

        constexpr int WinchMtr = 10; //changeTo ~ 3
        constexpr int ClawMtr = 1; //

        constexpr int PDP = 0;
        constexpr int PCM = 0;

    }//End CAN

    // Analog Devices Port IDs
    namespace ANALOG {
        constexpr int ClawPOT = 0;
    }//End Analog

    // Digital Devices Port IDs
    namespace DIGITAL {
        constexpr int Index_PE_feed = 1;
        constexpr int Hang_Limit_LOWER = 0;
        constexpr int ClawLowerLimit = 3;
        constexpr int ClawUpperLimit = 4;

        constexpr int driveUltrasonicPing = 6;
        constexpr int driveUltrasonicEcho = 7;
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

    // The Time Delay When Shooting to balls from the Indexers (in MilliSeconds)
    constexpr double k_shootTime = 2000;
    
    // The Color Proximity Trigger Value for GetFeedBall
    constexpr double k_colorProxTrigger= 100;

    constexpr double blueMinimum = 0.37;
    constexpr double blueMaximum = 0.2;

    constexpr double redMinimum = 0.45;
    constexpr double redMaximum = 0.3;

}//End kIndex

namespace kHang {

    namespace Claw{
        
        // The Claw Potentiometer Should Never Read ABOVE This Number
        constexpr int PotUpperLimit = 3500;
        // The Claw Potentiometer Should Never Read BELOW This Number
        constexpr int PotLowerLimit = 1200;

    }// End Claw

} // End kHang

namespace kDrive {
    constexpr double ultrasonicTV = 0.5;
}// End kDrive

//Macro to convert Talon FX encoder Units Per Rotation (UPR) into Rotations Per Minute (RPM)
#define c_TalonRPM(upr) (upr*600/2408)
#define c_TalonUPR(rpm) (rpm*2408/600)

#define fxMaxRPM 6300