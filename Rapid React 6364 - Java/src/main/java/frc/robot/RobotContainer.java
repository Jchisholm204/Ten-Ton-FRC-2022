package frc.robot;

//Import WPI
import edu.wpi.first.wpilibj2.command.Command;
import edu.wpi.first.wpilibj.XboxController;

//Import User Made Commands
import frc.robot.commands.*;

//Import User Made SubSystems
import frc.robot.subsystems.*;


/**
 * This Class should be where the bulk of the robot is declared.  This is a command based project.
 * {@link Robot} should be used for scheduler calls only
 */
public class RobotContainer {

    public final XboxController master = new XboxController(Constants.RobotMap.Controller_Main.port);
    public final XboxController partner = new XboxController(Constants.RobotMap.Controller_Partner.port);

    private final DriveSubsystem drive = new DriveSubsystem();
    private final IndexSubsystem indexer = new IndexSubsystem();
    private final IntakeSubsystem intake = new IntakeSubsystem();
    private final HangSubsystem hang = new HangSubsystem();

    private final OpDrive operatorDrive = new OpDrive(drive);
    private final OpIndex operatorIndex = new OpIndex(indexer);
    private final SimpleIndex simpleIndex = new SimpleIndex(indexer);
    private final OpIntake operatorIntake = new OpIntake(intake);
    private final SimpleIntakeCommand SimpleOpIntake = new SimpleIntakeCommand(intake);
    private final HangCommand hangCommand = new HangCommand(hang);

    public RobotContainer(){}

    public Command getOpDriveCommand(){
        return operatorDrive;
    }

    public Command getOpIndexCommand(){
        return operatorIndex;
    }

    public Command getSimpleIndexCommand(){
        return simpleIndex;
    }

    public Command getOpIntakeCommand(){
        return operatorIntake;
    }

    public Command getSimpleIntakeCommand(){
        return SimpleOpIntake;
    }

    public Command getHangCommand(){
        return hangCommand;
    }

    public XboxController getMaster(){
        return master;
    }

    public XboxController getPartner(){
        return partner;
    };
}
