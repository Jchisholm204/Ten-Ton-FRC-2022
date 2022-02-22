package frc.robot.commands;

import com.ctre.phoenix.motorcontrol.ControlMode;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.CommandBase;
import frc.robot.subsystems.HangSubsystem;
//import frc.robot.utilities.PID;


public class HangCommand extends CommandBase {

    private final HangSubsystem hang;

    private final double proValue = 1950;
    //private final PID pp = new PID((float) 0.045, 0, (int)proValue/1000);

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
        hang.setWinch(ControlMode.MotionMagic, SmartDashboard.getNumber("Targ", proValue));
        //pp.target = SmartDashboard.getNumber("pp.targ", proValue/100);
        //pp.current = hang.getWinch()/100;
        //SmartDashboard.putNumber("pp.current", pp.current);
        //hang.setWinch(ControlMode.PercentOutput, pp.output(0.1));

    }

    @Override
    public boolean isFinished() {
        return false;
    }

    @Override
    public void end(boolean interrupted) {
        hang.setWinch(ControlMode.PercentOutput, 0);
    }
}
