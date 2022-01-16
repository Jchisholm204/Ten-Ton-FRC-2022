package frc.robot.subsystems;

//Motor Imports
import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.can.TalonSRX;

//Pneumatics
import edu.wpi.first.wpilibj.Compressor;
import edu.wpi.first.wpilibj.Solenoid;

//WPI
import edu.wpi.first.wpilibj.DriverStation;
import edu.wpi.first.wpilibj.PneumaticsModuleType;
import edu.wpi.first.wpilibj2.command.SubsystemBase;

//Import Robot Files
import frc.robot.Constants;

public class IntakeSubsystem extends SubsystemBase {

    private TalonSRX intakeFront;
    private TalonSRX intakeRear;

    public Solenoid frontIntakeSolenoid;
    public Solenoid rearInakeSolenoid;

    private Compressor compressor;

    public IntakeSubsystem() {
        try {
            intakeFront = new TalonSRX(Constants.RobotMap.intakeFront.port);
            intakeRear = new TalonSRX(Constants.RobotMap.intakeFront.port);
        } catch (RuntimeException ex){
            DriverStation.reportError("Error Starting Intake Motors: " + ex.getMessage(), true);
        }

        compressor = new Compressor(0, PneumaticsModuleType.CTREPCM);
        frontIntakeSolenoid = new Solenoid(0, PneumaticsModuleType.CTREPCM, 1);
        rearInakeSolenoid = new Solenoid(0, PneumaticsModuleType.CTREPCM, 2);
    }
    
    /**
     * Lower One or Both of The Intakes
     * @param front Lower The Front Intake
     * @param rear Lower The Rear Intake
     */
    public void lowerIntake(boolean front, boolean rear){
        if(front){
            frontIntakeSolenoid.set(true);
        }
        if(rear){
            rearInakeSolenoid.set(true);
        }
    }

    /**
     * Raise One or Both of The Intakes
     * @param front Raise the Front Intake
     * @param rear Raise the Rear Intake
     */
    public void raiseIntake(boolean front, boolean rear){
        if(front){
            frontIntakeSolenoid.set(false);
        }
        if(rear){
            rearInakeSolenoid.set(false);
        }
    }

    /**
     * Get if the Intake is Up or Down
     * @return true if down
     */
    public boolean getFrontIntakeState(){
        return frontIntakeSolenoid.get();
    }

    /**
     * Get if the Intake is Up or Down
     * @return true if down
     */
    public boolean getRearIntakeState(){
        return rearInakeSolenoid.get();
    }

    /**
     * Starts the Pneumatic Compressor
     */
    public void startCompressor(){
        compressor.enableDigital();
    }

    /**
     * Disables The Compressor
     */
    public void stopCompressor(){
        compressor.disable();
    }

    /**
     * Gets if the Compressor is currently runnning
     * @return true if compressor compressing
     */
    public boolean compressorRunning(){
        return compressor.enabled();
    }

    /**
     * Run the Front and Back Intake Motors in Sync
     * @param Mode CTRE TalonSRX Control Mode
     * @param pVal Power Value
     */
    public void setIntake(ControlMode Mode, double pVal){
        intakeFront.set(Mode, pVal);
        intakeRear.set(Mode, pVal);
    }

    /**
     * Move Only the Front Intake
     * @param Mode CTRE Talon SRX Control Mode
     * @param pVal Power Value
     */
    public void setFrontIntake(ControlMode Mode, double pVal){
        intakeFront.set(Mode, pVal);
    }

    /**
     * Move Only the Rear Intake
     * @param Mode the CTRE Talon SRX Control Mode
     * @param pVal Power Value
     */
    public void setRearIntake(ControlMode Mode, double pVal){
        intakeRear.set(Mode, pVal);
    }

    /**
     * Stop the Intake
     * @param withdrawl Move the Intakes Inside the Robot
     */
    public void stop(boolean withdawl){
        intakeFront.set(ControlMode.PercentOutput, 0);
        intakeRear.set(ControlMode.PercentOutput, 0);
        if(withdawl){
            raiseIntake(true, true);
        }
    }

    @Override
    public void periodic(){
        // This Method will Run Periodically
    }
}
