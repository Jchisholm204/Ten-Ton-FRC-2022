package frc.robot.subsystems;

//Motor Imports
import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.can.TalonSRX;

//Sensor Imports
import edu.wpi.first.wpilibj.AnalogInput;
import edu.wpi.first.wpilibj.I2C;
import com.revrobotics.ColorSensorV3;
import edu.wpi.first.wpilibj.util.Color;

//WPI
import edu.wpi.first.wpilibj.DriverStation;
import edu.wpi.first.wpilibj2.command.SubsystemBase;

//Import Robot Files
import frc.robot.Constants;
import frc.robot.utilities.Talon;


public class IndexSubsystem extends SubsystemBase{

    private TalonSRX topMtr;
    private TalonSRX botMtr;
    private TalonSRX feedMtr;

    private static ColorSensorV3 colorSensor;

    private static AnalogInput topPESensor;
    private static AnalogInput botPESensor;
    private static AnalogInput intPESensor;

    public IndexSubsystem() {
        try {
            topMtr = new TalonSRX(Constants.RobotMap.indexTopMtr.port);
            botMtr = new TalonSRX(Constants.RobotMap.indexBotMtr.port);
            feedMtr = new TalonSRX(Constants.RobotMap.indexFeedMtr.port);
        } catch (RuntimeException ex){
            DriverStation.reportError("Error Starting Intake Motors: " + ex.getMessage(), true);
        }

        final I2C.Port ColorPort = I2C.Port.kOnboard;
        colorSensor = new ColorSensorV3(ColorPort);

        topPESensor = new AnalogInput(Constants.RobotMap.topIntakePE.port);
        botPESensor = new AnalogInput(Constants.RobotMap.botIntakePE.port);
        intPESensor = new AnalogInput(Constants.RobotMap.intIntakePE.port);

        //Motor Sensor Configuration
        Talon.Initialize.Index(topMtr, true);
        Talon.Initialize.Index(botMtr, true);
        Talon.Initialize.Index(feedMtr, false);

    }

    //Ball Colors
    public enum ballColor {
        // RED Ball
        red,
        // Blue Ball
        blue,
        // Undetermined Color // Try Adjusting Color Parameters
        UNDETERMINED,
        // No Ball in-front of Sensor
        noBall;
    }

    /**
     * Get The Current Balls Color
     * @return The Detected Ball Color
     */
    public ballColor getBallColor(){

        double redMax = 0.2; // The Maximum Value of RED to allow with a BLUE Ball
        double redMin = 0.3; // The Minimum Value of RED Required in a RED ball

        double blueMax = 0.2; // The Maximum Value of BLUE to allow with a RED Ball
        double blueMin = 0.3; // The Minimum Value of BLUE Required in a BLUE ball

        double minProximity = Constants.Index.colorProximityTriggerValue;

        if(getColorProximity() < minProximity){
            return ballColor.noBall;
        }
        else if(getColor().red > redMin && getColor().blue < blueMax){
            return ballColor.red;
        }
        else if(getColor().blue > blueMin && getColor().red < redMax){
            return ballColor.blue;
        }
        else{
            return ballColor.UNDETERMINED;
        }
    }

    /**
     * Reset The Codex Value
     */
    public void reset(){
        codex = 0;
    }

    /**
     * Get The Cargo Stored Within The Indexer Recorded By The Codex
     * @return The Value Stored Within The Codex
     */
    public int getCodex(){
        return codex;
    }

    /**
     * Move the Index Motors and Reset the Codex
     */
    public void shoot(){
        topMtr.set(ControlMode.PercentOutput, 1);
        botMtr.set(ControlMode.PercentOutput, 1);
        codex = 0;
    }

    
    public void shootSingle(){
        topMtr.set(ControlMode.PercentOutput, 1);
        codex = 0;
    }

    /**
     * Move The Top Index Motor
     * @param Mode Talon SRX Control Mode
     * @param pVal Power Value
     */
    public void setTop(ControlMode Mode, double pVal){
        topMtr.set(Mode, pVal);
    }

    /**
     * Move The Bottom Index Motor
     * @param Mode Talon SRX Control Mode
     * @param pVal Power Value
     */
    public void setBot(ControlMode Mode, double pVal){
        botMtr.set(Mode, pVal);
    }

    public void setFeed(ControlMode Mode, double pVal){
        feedMtr.set(Mode, pVal);
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
            return botMtr.getSelectedSensorVelocity() / Talon.rpmConverter;
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
        return topPESensor.getValue() > Constants.Index.topPHTriggerValue;
    }

    /**
     * Get if the Bottom PhotoElectric Sensor is Triggered
     * @return True if Triggered
     */
    public boolean getBotSensor(){
        return botPESensor.getValue() > Constants.Index.bottomPHTriggerValue;
    }

    /**
     * Get if the Intake PhotoElectric Sensor is Triggered
     * @return True if Triggered
     */
    public boolean getIntakeSensor(){
        return intPESensor.getValue() > Constants.Index.intakePHTriggerValue;
    }

    public Color getColor(){
        return colorSensor.getColor();
    }

    public int getColorProximity(){
        return colorSensor.getProximity();
    }

    public double getColorIR(){
        return colorSensor.getIR();
    }

}
