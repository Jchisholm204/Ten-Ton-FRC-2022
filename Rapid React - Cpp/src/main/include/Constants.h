// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

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

        constexpr int Intake_front = 0;
        constexpr int Intake_rear = 0;

        constexpr int driveRM = 0;
        constexpr int driveRS = 0;
        constexpr int driveLM = 0;
        constexpr int driveLS = 0;

        constexpr int TopIndex = 0;
        constexpr int BottomIndex = 0;
        constexpr int FeedIndex = 0;

    };

    // Analog Devices Port Numbers
    namespace ANALOG {
        constexpr int topPE = 0;
        constexpr int botPE = 1;
    };

    // PCM Controller IDs
    namespace PCM {

        constexpr int frontIntake = 0;
        constexpr int rearIntake = 1;

    };

    namespace DriverStation {

        constexpr int masterController = 0;
        constexpr int partnerController = 1;

    };
};

namespace driveConstants {
    constexpr double k_opTurnPow = 0.75;
}