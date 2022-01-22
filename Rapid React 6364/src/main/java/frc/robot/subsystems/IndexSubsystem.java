package frc.robot.subsystems;

//Motor Imports
import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.can.TalonSRX;
import com.ctre.phoenix.motorcontrol.FeedbackDevice;

//Sensor Imports
import edu.wpi.first.wpilibj.AnalogInput;

//WPI
import edu.wpi.first.wpilibj.DriverStation;
import edu.wpi.first.wpilibj2.command.SubsystemBase;

//Import Robot Files
import frc.robot.Constants;


public class IndexSubsystem extends SubsystemBase{

    private TalonSRX topMtr;
    private TalonSRX botMtr;

    private static double topPhotoElectricTrigger = 1000;
    private static double botPhotoElectricTrigger = 1000;

    private static AnalogInput topPESensor;
    private static AnalogInput botPESensor;

    public IndexSubsystem() {
        try {
            topMtr = new TalonSRX(Constants.RobotMap.indexTopMtr.port);
            botMtr = new TalonSRX(Constants.RobotMap.indexBotMtr.port);
        } catch (RuntimeException ex){
            DriverStation.reportError("Error Starting Intake Motors: " + ex.getMessage(), true);
        }
        
        topPESensor = new AnalogInput(Constants.RobotMap.topIntakePE.port);
        botPESensor = new AnalogInput(Constants.RobotMap.botIntakePE.port);

        //Motor Sensor Configuration
        topMtr.configSelectedFeedbackSensor(FeedbackDevice.SoftwareEmulatedSensor); //Set to use Emulated Sensor
        botMtr.configSelectedFeedbackSensor(FeedbackDevice.SoftwareEmulatedSensor); //Set to use Emulated Sensor

        //Motor Default Direction Configuration
        topMtr.setInverted(false);
        botMtr.setInverted(false);

    }

    /**
     * Move The Top Index Motor
     * @param Mode Talon SRX Control Mode
     * @param pVal Power Value
     */
    public void moveTop(ControlMode Mode, double pVal){
        topMtr.set(Mode, pVal);
    }

    /**
     * Move The Bottom Index Motor
     * @param Mode Talon SRX Control Mode
     * @param pVal Power Value
     */
    public void moveBot(ControlMode Mode, double pVal){
        botMtr.set(Mode, pVal);
    }

    /**
     * Get The Top Indexer Velocity
     * @param get_in_RPM True for RPM / False for Encoder Units
     * @return The Motors Current RPM
     */
    public double getTopVelocity(boolean get_in_RPM){
        if(get_in_RPM){
            return topMtr.getSelectedSensorVelocity() / Constants.kFalconEncoderUPR * 600.0;
        }
        else{
            return topMtr.getSelectedSensorVelocity();
        }
    }

        /**
     * Get The Bottom Indexer Velocity
     * @param get_in_RPM True for RPM / False for Encoder Units
     * @return The Motors Current RPM
     */
    public double getBotVelocity(boolean get_in_RPM){
        if(get_in_RPM){
            return botMtr.getSelectedSensorVelocity() / Constants.kFalconEncoderUPR * 600.0;
        }
        else{
            return botMtr.getSelectedSensorVelocity();
        }
    }

    /**
     * Stop The Top Index Motor
     */
    public void stopTop(){
        topMtr.set(ControlMode.PercentOutput, 0);
    }

    /**
     * Stop The Bottom Index Motor
     */
    public void stopBot(){
        botMtr.set(ControlMode.PercentOutput, 0);
    }

    /**
     * Stop All Indexer Motors
     */
    public void stop(){
        topMtr.set(ControlMode.PercentOutput, 0);
        botMtr.set(ControlMode.PercentOutput, 0);
    }

    /**
     * Get if the Top PhotoElectric Sensor is Triggered
     * @return True if Triggered
     */
    public boolean getTopSensor(){
        return topPESensor.getValue() > topPhotoElectricTrigger ? true : false;
    }

    /**
     * Get if the Bottom PhotoElectric Sensor is Triggered
     * @return True if Triggered
     */
    public boolean getBotSensor(){
        return botPESensor.getValue() > botPhotoElectricTrigger ? true : false;
    }

}
