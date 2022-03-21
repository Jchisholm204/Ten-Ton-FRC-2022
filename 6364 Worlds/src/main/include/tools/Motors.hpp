/**
 * 
 * Motor Configuration
 * 
 * @author Jacob Chisholm
 * TEAM: 6364
 * 
 */

#pragma once

#include "ctre/Phoenix.h"
#include "rev/CANSparkMax.h"
#include "rev/SparkMaxPIDController.h"



/**
 * Motor Configuration Utility
 * 
 * Used to:
 *  Apply Maximum and Minimum Outputs to Motor Controllers
 *  Define PID and Acceleration curves
 *  Apply PID and Acceleration curves to controllers
 *  Set Motor Controller Idle Modes
 *  Configure Feed Forward Values
 *  Configure Controller Primary Feedback Sensors
 * 
 * NOTE:
 * While Much of the Configuration is documented here, 
 * a large part of it as well as better explenations of how
 * things work can be found on the motor controllers documentation
 * page.  This would be the CTRE Phoenix documentation for the Talon 
 * and Falcon 500 Motor Controllers, and the REV documentation for
 * the Spark and Spark Max motor controllers.
 *  
 */
namespace motorConfiguration{

    /**
     * Apply a Configuration to a Talon Motor Controller
     */
    class Talon {

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

            /**
             * Apply Index Motor Configuration (Falcon500 Version)
             * @param iMotor The Motor to Apply The Configuration to
             * @param inverted Inverts the Default Direction of the Motor
             */
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

    /**
     * Apply a Configuration to a Spark Max Motor Controller
     */
    class SparkMax{

        public:
            /**
             * Apply Index Motor Configuration
             * @param iMotor The Motor to Apply The Configuration to
             * @param inverted Inverts the Default Direction of the Motor
             */
            static void index(rev::SparkMaxPIDController &iController, rev::CANSparkMax &iMotor, bool inverted);

    };

}