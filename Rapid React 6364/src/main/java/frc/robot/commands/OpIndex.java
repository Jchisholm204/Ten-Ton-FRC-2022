package frc.robot.commands;

//Motor Dependancies
import com.ctre.phoenix.motorcontrol.ControlMode;

//Import WPI
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.CommandBase;

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
        System.out.print(indxr.getCodex());
        System.out.print("\n");
        

        //Shoot the Balles when A master Pressed
        if(Robot.io.master.getRightBumperPressed()){
            indxr.shoot(); 
        }
        else if(Robot.io.master.getLeftBumper()){
            indxr.moveTop(ControlMode.PercentOutput, -0.5);
            indxr.moveBot(ControlMode.PercentOutput, -0.5);
        }
        else{
            indxr.run(0.8, 1);
        }

    }

    @Override
    public void end(boolean interrupted){
        indxr.stop();
    }

    @Override
    public boolean isFinished(){
        return false;
    }
}
