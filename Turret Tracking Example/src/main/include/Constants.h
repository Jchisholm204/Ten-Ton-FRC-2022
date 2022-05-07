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


namespace RobotMap
{
    namespace CAN
    {
        constexpr int TurretMotor = 0;
        constexpr int FlyWheelMotor = 2;
        constexpr int BackSpinMotor = 3;
        constexpr int FWFeedMotor = 4;
    } // namespace CAN
} // namespace RobotContainer

namespace Turret
{
    constexpr float kP = 1.0;
    constexpr float kI = 0.0;
    constexpr float kD = 0.0;
} // namespace Turret