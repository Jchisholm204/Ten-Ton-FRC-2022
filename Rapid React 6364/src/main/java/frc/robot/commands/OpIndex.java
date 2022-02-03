package frc.robot.commands;

//Motor Dependencies
import com.ctre.phoenix.motorcontrol.ControlMode;

//Import WPI
import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.CommandBase;
import edu.wpi.first.wpilibj.XboxController;

//Import Robot Files
import frc.robot.subsystems.IndexSubsystem;
import frc.robot.Robot;

import javax.swing.*;

public class OpIndex extends CommandBase {
    private final IndexSubsystem indexer;
    private final double waitTime = 2; // Seconds To Wait While Shooting
    private double WaitSaveTime;

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



        // Shooting | Running Index \\
        if(Timer.getFPGATimestamp() < (WaitSaveTime + waitTime)){
            //Do Nothing
            //Wait For Shot to finish
        }
        else if(Robot.robotContainer.master.getRightBumperPressed()){
            indexer.shoot();
            WaitSaveTime = Timer.getFPGATimestamp();
        }
        else if(Robot.robotContainer.master.getLeftBumper()){
            indexer.setTop(ControlMode.PercentOutput, -0.5);
            indexer.setBot(ControlMode.PercentOutput, -0.5);
        }
        else{
            indexer.runCodex(0.8, 1);
        }

        //Run Feeder Motor (Sideways Index Module)
        if(indexer.getCodex() == 2){
            indexer.setFeed(ControlMode.PercentOutput, 0.1); //Slow down when index full
        }
        else{
            indexer.setFeed(ControlMode.PercentOutput, 1);
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
