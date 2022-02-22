package frc.robot.subsystems;

//Motor Imports
import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.can.TalonSRX;
import frc.robot.utilities.Talon;

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
    public Solenoid rearIntakeSolenoid;

    private Compressor compressor;

    public IntakeSubsystem() {
        try {
            intakeFront = new TalonSRX(Constants.RobotMap.intakeFront.port);
            intakeRear = new TalonSRX(Constants.RobotMap.intakeRear.port);
        } catch (RuntimeException ex){
            DriverStation.reportError("Error Starting Intake Motors: " + ex.getMessage(), true);
        }

        try {
            compressor = new Compressor(0, PneumaticsModuleType.CTREPCM);
            frontIntakeSolenoid = new Solenoid(0, PneumaticsModuleType.CTREPCM, 1);
            rearIntakeSolenoid = new Solenoid(0, PneumaticsModuleType.CTREPCM, 2);
        } catch (RuntimeException e){
            DriverStation.reportError("Error Starting Pneumatics System: " + e.getMessage(), true);
        }

        Talon.Initialize.Intake(intakeFront, false);
        Talon.Initialize.Intake(intakeRear, false);

    }
    
    /**
     * Lower One or Both of The Intakes
     * @param front Lower The Front Intake
     * @param rear Lower The Rear Intake
     */
    public void lower(boolean front, boolean rear){
        if(front){
            frontIntakeSolenoid.set(true);
        }
        if(rear){
            rearIntakeSolenoid.set(true);
        }
    }

    /**
     * Raise One or Both of The Intakes
     * @param front Raise the Front Intake
     * @param rear Raise the Rear Intake
     */
    public void raise(boolean front, boolean rear){
        if(front){
            frontIntakeSolenoid.set(false);
        }
        if(rear){
            rearIntakeSolenoid.set(false);
        }
    }

    /**
     * Get if the Intake is Up or Down
     * @return true if down
     */
    public boolean getFrontState(){
        return frontIntakeSolenoid.get();
    }

    /**
     * Get if the Intake is Up or Down
     * @return true if down
     */
    public boolean getRearState(){
        return rearIntakeSolenoid.get();
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
     * Gets if the Compressor is currently running
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
    public void set(ControlMode Mode, double pVal){
        intakeFront.set(Mode, pVal);
        intakeRear.set(Mode, pVal);
    }

    /**
     * Move Only the Front Intake
     * @param Mode CTRE Talon SRX Control Mode
     * @param pVal Power Value
     */
    public void setFront(ControlMode Mode, double pVal){
        intakeFront.set(Mode, pVal);
    }

    /**
     * Move Only the Rear Intake
     * @param Mode the CTRE Talon SRX Control Mode
     * @param pVal Power Value
     */
    public void setRear(ControlMode Mode, double pVal){
        intakeRear.set(Mode, pVal);
    }

    /**
     * Stop the Intake
     * @param withdrawal Move the Intakes Inside the Robot
     */
    public void stop(boolean withdrawal){
        intakeFront.set(ControlMode.PercentOutput, 0);
        intakeRear.set(ControlMode.PercentOutput, 0);
        if(withdrawal){
            raise(true, true);
        }
    }

    @Override
    public void periodic(){
        // This Method will Run Periodically
    }
}
