package frc.robot.subsystems;

//Motor Imports
import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.can.TalonFX;
import frc.robot.utilities.InitializeTalon;

//WPI
import edu.wpi.first.wpilibj.DriverStation;
import edu.wpi.first.wpilibj2.command.SubsystemBase;

//Import Robot Files
import frc.robot.Constants;


public class IndexSubsystem extends SubsystemBase{

    private TalonFX indexShooter;
    private TalonFX indexFeeder;

    public IndexSubsystem() {
        try {
            indexShooter = new TalonFX(Constants.RobotMap.indexShooter.port);
            indexFeeder = new TalonFX(Constants.RobotMap.indexFeeder.port);
        } catch (RuntimeException ex){
            DriverStation.reportError("Error Starting Intake Motors: " + ex.getMessage(), true);
        }
        
        InitializeTalon.Index(indexShooter, false);
        InitializeTalon.Index(indexFeeder, false);
    }

    public void index(ControlMode Mode, double pVal){
        indexFeeder.set(Mode, pVal);
    }

    public double getFeederVelocity(boolean get_in_RPM){
        if(get_in_RPM){
            return indexFeeder.getSelectedSensorVelocity() / Constants.kFalconEncoderUPR * 600.0;
        }
        else{
            return indexFeeder.getSelectedSensorVelocity();
        }
    }

    public void stopFeeder(){
        indexFeeder.set(ControlMode.PercentOutput, 0);
    }

    public void shoot(ControlMode Mode, double pVal){
        indexShooter.set(Mode, pVal);
    }

    public double getShooterVelocity(boolean get_in_RPM){
        if(get_in_RPM){
            return indexShooter.getSelectedSensorVelocity() / Constants.kFalconEncoderUPR * 600.0;
        }
        else{
            return indexShooter.getSelectedSensorVelocity();
        }
    }

    public void stopShooter(){
        indexShooter.set(ControlMode.PercentOutput, 0);
    }

}
