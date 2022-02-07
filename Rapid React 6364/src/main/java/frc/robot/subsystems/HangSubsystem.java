package frc.robot.subsystems;


import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.can.TalonFX;
import edu.wpi.first.wpilibj.DriverStation;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import frc.robot.Constants;
import frc.robot.utilities.Talon;

public class HangSubsystem extends SubsystemBase {

    private TalonFX winchMotor;
    private TalonFX hangMotor;

    public HangSubsystem() {
        try {
            winchMotor = new TalonFX(Constants.RobotMap.winchMtr.port);
            hangMotor = new TalonFX(Constants.RobotMap.hangMtr.port);
        } catch (Exception e){
            DriverStation.reportError("Error Starting Hang Talons: " + e.getMessage(), true);
        }

        Talon.Initialize.GenericFX(winchMotor, false);
        Talon.Initialize.GenericFX(hangMotor, false);

    }

    public void setWinch(ControlMode Mode, double iPow){
        winchMotor.set(Mode, iPow);
    }

    public void setHang(ControlMode Mode, double iPow){
        hangMotor.set(Mode, iPow);
    }

}

