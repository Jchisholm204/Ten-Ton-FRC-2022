package frc.robot.commands;

import com.ctre.phoenix.motorcontrol.ControlMode;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.CommandBase;
import frc.robot.subsystems.HangSubsystem;
import frc.robot.utilities.PID;


public class HangCommand extends CommandBase {

    private final HangSubsystem hang;

    public HangCommand(final HangSubsystem hangSubsystem) {
        hang = hangSubsystem;
        addRequirements(hangSubsystem);

    }

    @Override
    public void initialize() {
        SmartDashboard.putNumber("Targ", hang.getWinch());
    }

    @Override
    public void execute() {
        SmartDashboard.putNumber("Cur", hang.getWinch());
        hang.setHang(ControlMode.Position, SmartDashboard.getNumber("Targ", hang.getWinch()));

    }

    @Override
    public boolean isFinished() {
        // TODO: Make this return true when this Command no longer needs to run execute()
        return false;
    }

    @Override
    public void end(boolean interrupted) {
        hang.setHang(ControlMode.PercentOutput, 0);
        hang.setWinch(ControlMode.PercentOutput, 0);
    }
}
