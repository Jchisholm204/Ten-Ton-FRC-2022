package frc.robot.commands;

//Motor Dependencies
import com.ctre.phoenix.motorcontrol.ControlMode;

//Import WPI
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.CommandBase;
import edu.wpi.first.wpilibj.XboxController;

//Import Robot Files
import frc.robot.mapping.Controller;
import frc.robot.subsystems.IndexSubsystem;
import frc.robot.Robot;

public class OpIndex extends CommandBase {
    private final IndexSubsystem indexer;
    private final XboxController master = Controller.getMaster();


    public OpIndex(final IndexSubsystem indexSubSys){
        indexer = indexSubSys;
        addRequirements(indexer);
    }
    
    @Override
    public void initialize(){
        indexer.stop();
    }

    @Override
    public void execute(){
        SmartDashboard.putNumber("Codex", indexer.getCodex());
        SmartDashboard.putBoolean("topPE", indexer.getTopSensor());
        SmartDashboard.putBoolean("botPE", indexer.getBotSensor());
        

        //Shoot the Balls when A master Pressed
        if(master.getRightBumperPressed()){
            indexer.shoot();
        }
        else if(master.getLeftBumper()){
            indexer.moveTop(ControlMode.PercentOutput, -0.5);
            indexer.moveBot(ControlMode.PercentOutput, -0.5);
        }
        else{
            indexer.run(0.8, 1);
        }

    }

    @Override
    public void end(boolean interrupted){
        indexer.stop();
    }

    @Override
    public boolean isFinished(){
        return false;
    }
}
