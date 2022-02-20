#pragma once
/** Container.hpp
 * Contains all of the Universal Declarations for the Robot
 * (Motors, Controllers, Sensors, ..ext)
 */

#include "ctre/Phoenix.h"
#include <frc/XboxController.h>
#include <frc/AnalogInput.h>

// Controllers
extern frc::XboxController master;
extern frc::XboxController partner;

/*\  // Motors \\  \*/

// Right Drive
extern TalonFX driveRM;
extern TalonFX driveRS;
// Left Drive
extern TalonFX driveLM;
extern TalonFX driveLS;

// Intake Motors
extern TalonSRX IntakeFront;
extern TalonSRX IntakeRear;