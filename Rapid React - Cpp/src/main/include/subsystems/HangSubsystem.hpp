#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"

class HangSubsystem : public frc2::SubsystemBase {
    public:
        HangSubsystem();

        void setWinch(ControlMode mode, double iPow);
        
    private:
        TalonFX winchMtr;
};