package frc.robot.commands;

import edu.wpi.first.wpilibj2.command.CommandBase;
import frc.robot.subsystems.IntakeSubsystem;
import frc.robot.Robot;
import com.ctre.phoenix.motorcontrol.ControlMode;


public class SimpleIntakeCommand extends CommandBase {
    private final IntakeSubsystem intake;

    public SimpleIntakeCommand(IntakeSubsystem intakeSubsystem) {
        this.intake = intakeSubsystem;
        // each subsystem used by the command must be passed into the
        // addRequirements() method (which takes a vararg of Subsystem)
        addRequirements(this.intake);
    }

    /**
     * The initial subroutine of a command.  Called once when the command is initially scheduled.
     */
    @Override
    public void initialize() {
        intake.stop(false);
    }

    /**
     * The main body of a command.  Called repeatedly while the command is scheduled.
     * (That is, it is called repeatedly until {@link #isFinished()}) returns true.)
     */
    @Override
    public void execute() {
        //Front Intake Control
        if (Robot.robotContainer.master.getAButton()){
            intake.setFront(ControlMode.PercentOutput, 1);
        }
        else if(Robot.robotContainer.master.getYButton()){
            intake.setFront(ControlMode.PercentOutput, -1);
        }
        else{
            intake.setFront(ControlMode.PercentOutput, 0);
        }

        //Rear intake Control
        if(Robot.robotContainer.master.getBButton()){
            intake.setRear(ControlMode.PercentOutput, 1);
        }
        else if(Robot.robotContainer.master.getXButton()){
            intake.setRear(ControlMode.PercentOutput, -1);
        }
        else{
            intake.setRear(ControlMode.PercentOutput, 0);
        }
    }

    /**
     * <p>
     * Returns whether this command has finished. Once a command finishes -- indicated by
     * this method returning true -- the scheduler will call its {@link #end(boolean)} method.
     * </p><p>
     * Returning false will result in the command never ending automatically. It may still be
     * cancelled manually or interrupted by another command. Hard coding this command to always
     * return true will result in the command executing once and finishing immediately. It is
     * recommended to use * {@link edu.wpi.first.wpilibj2.command.InstantCommand InstantCommand}
     * for such an operation.
     * </p>
     *
     * @return whether this command has finished.
     */
    @Override
    public boolean isFinished() {
        return false;
    }

    /**
     * The action to take when the command ends. Called when either the command
     * finishes normally -- that is it is called when {@link #isFinished()} returns
     * true -- or when  it is interrupted/canceled. This is where you may want to
     * wrap up loose ends, like shutting off a motor that was being used in the command.
     *
     * @param interrupted whether the command was interrupted/canceled
     */
    @Override
    public void end(boolean interrupted) {
        intake.stop(false);
    }
}
