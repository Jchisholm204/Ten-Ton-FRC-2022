#include <frc2/command/SubsystemBase.h>
#include <frc/PowerDistribution.h>
#include "ctre/Phoenix.h"

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

        /**
         * Get The Winch Motors Current RPM
         * @return Revolutes Per Min
         */
        double getWinchRPM();

        /**
         * Get The Winch Motors Power Draw from the PDP
         * @return The Winches Power Draw in Amps
         */
        double getWinchDraw() const;

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
         * Get The Claws Current RPM
         * @return Revolutes Per Min
         */
        double getClawRPM();

        
    private:
        TalonFX winchMtr;
        TalonFX clawMtr;
};