package frc.robot.commands;

import com.ctre.phoenix.motorcontrol.ControlMode;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.CommandBase;
import frc.robot.subsystems.HangSubsystem;


public class HangCommand extends CommandBase {

    private final HangSubsystem hang;

    public HangCommand(final HangSubsystem hangSubsystem) {
        hang = hangSubsystem;
        addRequirements(hangSubsystem);

    }

    @Override
    public void initialize() {
        SmartDashboard.putNumber("Hang", 0.00);
        SmartDashboard.putNumber("Winch", 0.00);
    }

    @Override
    public void execute() {
        hang.setHang(ControlMode.PercentOutput, (SmartDashboard.getNumber("Hang", 0)/100));
        hang.setWinch(ControlMode.PercentOutput, (SmartDashboard.getNumber("Winch", 0)/100));
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
