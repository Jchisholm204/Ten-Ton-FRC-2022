package frc.robot.commands;

//Motor Dependancies
import com.ctre.phoenix.motorcontrol.ControlMode;

//Robot Files
import frc.robot.subsystems.DriveSubsystem;
import frc.robot.utilities.Exponential;
import frc.robot.Robot;

//WPI
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.CommandBase;
import edu.wpi.first.wpilibj.XboxController;

public class OpDrive extends CommandBase{
    private final DriveSubsystem drivef;

    //Exp Controller Variables
    private final double joyDead = 0.050;
    private final double driveExp = 1.7;
    private final double motorMin = 0.008;

    public OpDrive(final DriveSubsystem driveSubSys){
        drivef = driveSubSys;
        addRequirements(drivef);
    }

    @Override
    public void initialize(){}

    @Override
    public void execute(){

        //Smart Dashboard
        SmartDashboard.putNumber("Right Drive RPM", drivef.getRightRPM());
        SmartDashboard.putNumber("Left Drive RPM", drivef.getLeftRPM());
        SmartDashboard.putNumber("GyroVal", drivef.getAngle());

        //Robot Drive Code
        double Yval = 21000 * Exponential.exponential(Robot.robotContainer.master.getLeftY(), driveExp, joyDead, motorMin);
        double Xval = 21000 * Exponential.exponential(Robot.robotContainer.master.getRightX(), driveExp, joyDead, motorMin);

        //Arcade Drive Configuration
        drivef.set(ControlMode.Velocity, (Yval - Xval), (Yval + Xval));
    }

    @Override
    public void end(boolean interrupted){
        drivef.stop();
    }

    //Returns true when command should end.
    @Override
    public boolean isFinished(){
        return false;
    }
}
