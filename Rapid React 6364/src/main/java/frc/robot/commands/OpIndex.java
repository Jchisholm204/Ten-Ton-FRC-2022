package frc.robot.commands;

//Motor Dependancies
import com.ctre.phoenix.motorcontrol.ControlMode;

//Import WPI
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.CommandBase;
import edu.wpi.first.wpilibj.Timer;

//Import Robot Files
import frc.robot.subsystems.IndexSubsystem;
import frc.robot.Robot;

public class OpIndex extends CommandBase {
    private IndexSubsystem indxr;

    public OpIndex(final IndexSubsystem indexSubSys){
        indxr = indexSubSys;
        addRequirements(indxr);
    }
    
    @Override
    public void initialize(){
        indxr.stop();
    }

    @Override
    public void execute(){
        System.out.print(indxr.getBotSensor());
        System.out.print(" ");
        System.out.print(indxr.getTopSensor());
        System.out.print("\n");
        

        //Shoot the Balles when A master Pressed
        if(Robot.io.master.getAButton()){
            indxr.moveTop(ControlMode.PercentOutput, 1);
            indxr.moveBot(ControlMode.PercentOutput, 1);
            //Timer.delay(2);
        }
        else{
            indxr.stop();
        }

    }

    @Override
    public void end(boolean interrupted){

    }

    @Override
    public boolean isFinished(){
        return false;
    }
}
