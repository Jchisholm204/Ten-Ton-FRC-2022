package frc.robot.systems;

import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.can.TalonSRX;
import edu.wpi.first.wpilibj.DriverStation;

import frc.robot.Constants;

public class Intake{
    private TalonSRX indexBot;
    private TalonSRX indexTop;
    private TalonSRX intakeMtr;

    public Intake(){
        try{
            indexTop = new TalonSRX(Constants.RobotMap.INDEX_TOP.value);
            indexBot = new TalonSRX(Constants.RobotMap.INDEX_BOT.value);
            intakeMtr = new TalonSRX(Constants.RobotMap.INTAKE_MTR.value);
        } catch(RuntimeException ex){
            DriverStation.reportError("Error Starting TalonSRX" + ex.getMessage(), true);
        }
    }

    /**
     * Run the Front Intake Motor With a given power
     * @param speed The Percent Power [-100, 100]
     */
    public void run(double speed){
        intakeMtr.set(ControlMode.PercentOutput, speed/100);
    }

    /**
     * Run the Indexer Motors With a given power
     * @param speed The Percent Power [-100, 100]
     */
    public void index(double speed){
        indexTop.set(ControlMode.PercentOutput, speed/100);
        indexBot.set(ControlMode.PercentOutput, speed/100);
    }
}
