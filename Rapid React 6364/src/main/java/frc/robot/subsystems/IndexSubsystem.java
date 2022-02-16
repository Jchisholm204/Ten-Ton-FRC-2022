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

    private static int codex = 0;

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

        if(getColorProximity() < Constants.Index.Color.ProxTrigger){
            return ballColor.noBall;
        }
        else if(getColor().red > Constants.Index.Color.redMin && getColor().blue < Constants.Index.Color.blueMax){
            return ballColor.red;
        }
        else if(getColor().blue > Constants.Index.Color.blueMin && getColor().red < Constants.Index.Color.redMax){
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

    /**
     * Run The Codex Program
     * @param topMper Top Motor Percent Power [0,1]
     * @param botMper Bottom Motor Percent Power [0,1]
     */
    public void runCodex(double topMper, double botMper){

        if ( getTopSensor() && codex == 0){ codex = 1; };
        if ( getBotSensor() && codex == 1 ){ codex = 2; };

        if ( codex == 2 ){
            topMtr.set(ControlMode.PercentOutput, 0);
            botMtr.set(ControlMode.PercentOutput, 0);
        }
        else if ( codex == 1 ){
            topMtr.set(ControlMode.PercentOutput, 0);
            botMtr.set(ControlMode.PercentOutput, botMper);
        }
        else if ( codex == 0 ){
            topMtr.set(ControlMode.PercentOutput, topMper);
            botMtr.set(ControlMode.PercentOutput, botMper);
        }
        else {
            DriverStation.reportError("Codex Overload: " + codex, true);
            codex = 0;
        };
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
     * Stop Top/Bot Indexer Motors
     */
    public void stop(){
        topMtr.set(ControlMode.PercentOutput, 0);
        botMtr.set(ControlMode.PercentOutput, 0);
    }

    /**
     * Stop Feed Motor
     */
    public void stopFeed(){
        feedMtr.set(ControlMode.PercentOutput, 0);
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
