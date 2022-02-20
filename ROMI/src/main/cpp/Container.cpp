/* *Container*
* Contains all Definitions of Physical Robot Components */

#include "Container.hpp"
#include <frc/AnalogInput.h>
#include <frc/XboxController.h>
#include "ctre/Phoenix.h"

// Controllers
frc::XboxController master(0);
frc::XboxController partner(0);

// Motors
TalonFX driveRM(0);
TalonFX driveRS(0);
TalonFX driveLM(0);
TalonFX driveLS(0);

TalonSRX IntakeFront(0);
TalonSRX IntakeRear(0);