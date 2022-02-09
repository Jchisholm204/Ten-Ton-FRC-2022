package frc.robot.commands;

import com.ctre.phoenix.motorcontrol.ControlMode;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.CommandBase;
import frc.robot.subsystems.HangSubsystem;
import frc.robot.utilities.PID;


public class HangCommand extends CommandBase {

    private final HangSubsystem hang;

    private final double proValue = 1950;

    public HangCommand(final HangSubsystem hangSubsystem) {
        hang = hangSubsystem;
        addRequirements(hangSubsystem);

    }

    @Override
    public void initialize() {
        SmartDashboard.putNumber("Targ", proValue);
    }

    @Override
    public void execute() {
        SmartDashboard.putNumber("Cur", hang.getWinch());
        hang.setWinch(ControlMode.Position, SmartDashboard.getNumber("Targ", proValue));

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
