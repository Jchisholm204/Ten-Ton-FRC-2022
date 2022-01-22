package frc.robot.commands;

//Motor Dependancies
import com.ctre.phoenix.motorcontrol.ControlMode;

//Import WPI
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.CommandBase;

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
    public void initialize(){}

    @Override
    public void execute(){
        SmartDashboard.putBoolean("PhElectric", indxr.getTopDetector());

    }

    @Override
    public void end(boolean interrupted){

    }

    @Override
    public boolean isFinished(){
        return false;
    }
}
