package frc.robot.subsystems;

//Motor Imports
import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.can.TalonSRX;

//Sensor Imports
import edu.wpi.first.wpilibj.AnalogInput;

//WPI
import edu.wpi.first.wpilibj.DriverStation;
import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj2.command.SubsystemBase;

//Import Robot Files
import frc.robot.Constants;
import frc.robot.utilities.Talon;


public class IndexSubsystem extends SubsystemBase{

    private TalonSRX topMtr;
    private TalonSRX botMtr;

    private static AnalogInput topPESensor;
    private static AnalogInput botPESensor;

    //initialize the codex to track balls inside the intake
    private static int codex = 0;

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
        Talon.Initialize.Index(topMtr, true);
        Talon.Initialize.Index(botMtr, true);

    }

    /**
     * Run The Codex Program
     * @param topMper Top Motor Percent Power [0,1]
     * @param botMper Bottom Motor Percent Power [0,1]
     */
    public void run(double topMper, double botMper){

        if ( getTopSensor() ){ codex = 1; };
        if ( codex == 1 && getBotSensor() ){ codex = 2; };

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
     * Shoot The Cargo Stored Within The Index (delay = 2sec)
     */
    public void shoot(){
        topMtr.set(ControlMode.PercentOutput, 1);
        botMtr.set(ControlMode.PercentOutput, 1);
        codex = 0;
        Timer.delay(2);
    }

    /**
     * Shoot The Cargo Stored Within The Index (delay = 2sec)
     * @param runTime Delay In Seconds to Run The Indexer
     */
    public void shoot(double runTime){
        topMtr.set(ControlMode.PercentOutput, 1);
        botMtr.set(ControlMode.PercentOutput, 1);
        Timer.delay(runTime); 
    }
    
    public void shootSingle(){
        topMtr.set(ControlMode.PercentOutput, 1);
        codex = 0;
        Timer.delay(1);
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

}
