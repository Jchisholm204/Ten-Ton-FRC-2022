package frc.robot.commands;

//Motor Dependancies
import com.ctre.phoenix.motorcontrol.ControlMode;

//Import WPI
import edu.wpi.first.wpilibj2.command.CommandBase;

//Import Robot Files
import frc.robot.subsystems.IntakeSubsystem;
import frc.robot.Robot;


public class OpIntake extends CommandBase {
    private IntakeSubsystem intake;

    public OpIntake(final IntakeSubsystem intakeSubSys){
        intake = intakeSubSys;
        addRequirements(intake);
    }

    @Override
    public void initialize(){
        intake.startCompressor();
        intake.raise(true, true);
    }

    @Override
    public void execute(){
        
        if(Robot.io.master.getLeftBumperPressed()){
            intake.raise(true, true);
        }
        else if(Robot.io.master.getRightBumperPressed()){
            intake.lower(true, true);
        };

        if(Robot.io.master.getBButton()){
            intake.set(ControlMode.PercentOutput, -1);
        }
        else if(intake.getFrontState() == true){
            intake.setFront(ControlMode.PercentOutput, 1);
        }
        else{
            intake.setFront(ControlMode.PercentOutput, 0);
        };

        if(Robot.io.master.getXButton()){
            intake.set(ControlMode.PercentOutput, -1);
        }
        else if(intake.getRearState() == true){
            intake.set(ControlMode.PercentOutput, 1);
        }
        else{
            intake.setRear(ControlMode.PercentOutput, 0);
        }

    }

    @Override
    public void end(boolean interrupted){
        intake.stopCompressor();
        intake.stop(false);
    }

    @Override
    public boolean isFinished(){
        return false;
    }
}