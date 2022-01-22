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

        //Shoot the Balles when A master Pressed
        if(Robot.io.master.getAButtonPressed()){
            indxr.moveTop(ControlMode.PercentOutput, 1);
            indxr.moveBot(ControlMode.PercentOutput, 1);
            Timer.delay(10);
        }
        else{
            /** When Not Shooting
             * If top has ball = stop top
             *  Else: Intake Top/Bot
             * If Top AND Bot Have Ball = Stop Bot (Top already stopped)
             */
            if(indxr.getTopSensor() == true){
                indxr.stopTop();
                if(indxr.getBotSensor() == true){
                    indxr.stopBot();
                }
            }
            else{
                indxr.moveTop(ControlMode.PercentOutput, 1);
                indxr.moveBot(ControlMode.PercentOutput, 1);
            }
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
