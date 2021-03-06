package frc.robot;

//Import WPI
import edu.wpi.first.wpilibj2.command.Command;

//Import User Made Commands
import frc.robot.commands.*;

//Import User Made SubSystems
import frc.robot.subsystems.*;


/**
 * This Class should be where the bulk of the robot is declared.  This is a command based project.
 * {@link Robot} should be used for scheduler calls only
 */
public class RobotContainer {

    private final DriveSubsystem drive = new DriveSubsystem();
    private final IndexSubsystem indexer = new IndexSubsystem();
    private final IntakeSubsystem intake = new IntakeSubsystem();

    private final OpDrive operatorDrive = new OpDrive(drive);
    private final OpIndex operatorIndex = new OpIndex(indexer);
    private final OpIntake operatorIntake = new OpIntake(intake);

    public RobotContainer(){}

    public Command getOpDriveCommand(){
        return operatorDrive;
    }

    public Command getOpIndexCommand(){
        return operatorIndex;
    }

    public Command getOpIntakeCommand(){
        return operatorIntake;
    }
}
