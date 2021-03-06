#pragma once

#include "ctre/Phoenix.h"

/**
 * Apply a Configuation to a Motor
 */
class TalonConfiguation {

    public:

        /**
         * Apply Intake Motor Configuration
         * @param iMotor The Motor to Apply The Configuration to
         * @param inverted Inverts the Default Direction of the Motor
         */
        static void intake(TalonSRX &iMotor, bool inverted);

         /**
         * Apply Index Motor Configuration
         * @param iMotor The Motor to Apply The Configuration to
         * @param inverted Inverts the Default Direction of the Motor
         */
        static void index(TalonSRX &iMotor, bool inverted);
        
        static void index(TalonFX &iMotor, bool inverted);

         /**
         * Apply Right Drive Motor Configuration
         * @param iMotor The Motor to Apply The Configuration to
         */
        static void rightDrive(TalonFX &iMotor);

         /**
         * Apply Left Drive Motor Configuration
         * @param iMotor The Motor to Apply The Configuration to
         */
        static void leftDrive(TalonFX &iMotor);

        /**
         * Apply the Winch Motor Configuration
         * @param iMotor The Winch Motor
         */
        static void winchMotor(TalonFX &iMotor);

         /**
         * Apply the Claw Motor Configuration
         * @param iMotor The Claw Motor
         */
        static void clawMotor(TalonFX &iMotor);
};