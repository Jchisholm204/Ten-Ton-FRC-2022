#include <frc2/command/SubsystemBase.h>
#include <frc/PowerDistribution.h>
#include <frc/Solenoid.h>
#include "ctre/Phoenix.h"
#include <frc/DigitalInput.h>

class HangSubsystem : public frc2::SubsystemBase {
    public:
        HangSubsystem();

        /**
         * Set the Winch Motor
         * @param mode The CTRE Control Mode
         * @param iPow The Applied Power
         */
        void setWinch(ControlMode mode, double iPow);

        /**
         * Get The Winches Selected Sensor Position
         * @return The Sensor Position
         */
        double getWinch();

        void resetWinch();

        /**
         * Get The Winch Motors Current RPM
         * @return Revolutes Per Min
         */
        double getWinchRPM();

        /**
         * Get The Winch Motors Power Draw from the PDP
         * @return The Winches Power Draw in Amps
         */
        double getWinchDraw();

        /**
         * Set the Claw Motor
         * @param mode The CTRE Control Mode
         * @param iPow The Applied Power
         */
        void setClaw(ControlMode mode, double iPow);

        /**
         * Get The Claws Selected Sensor Position
         * @return The Sensor Position
         */
        double getClaw();

        /**
         * Reset The Claws Encoder Position
         * Sets the Encoder to 0
         */
        void resetClaw();

        /**
         * Get The Claws Current RPM
         * @return Revolutes Per Min
         */
        double getClawRPM();

        /**
         * Activate the Hang Arm Pneumatic Cylinder
         * @param on True to apply pressure, False to release pressure
         */
        void ApplyPressure(bool on);

        /**
         * Get if there is currently pressure within the Hang arm Pneumatic
         * @return true if the cylinder is extended
         */
        bool GetPressure();

        // Claw Upper Bound Limit Switch
        frc::DigitalInput limit_ClawUpper;
        // Claw Lower Bound Limit Switch
        frc::DigitalInput limit_ClawLower;
        // Hang Arm / Winch Lower Bound Limit Switch
        frc::DigitalInput limit_HangLower;
        
    private:
        TalonFX winchMtr;
        TalonFX clawMtr;
        frc::Solenoid arm;
};