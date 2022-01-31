package frc.robot.ReRun;

import com.ctre.phoenix.motorcontrol.ControlMode;
import edu.wpi.first.wpilibj.DriverStation;
import edu.wpi.first.wpilibj2.command.CommandBase;
import frc.robot.subsystems.*;
import frc.robot.Robot;

import java.io.*;
import java.util.Scanner;


public class RunCommand extends CommandBase {
    private final DriveSubsystem drive;
    private final IndexSubsystem index;
    private final IntakeSubsystem intake;

    private File recordFile;
    private Scanner reader;
    private boolean isNewFile;

    private boolean Finished = false;

    public RunCommand(DriveSubsystem driveSubsystem, IndexSubsystem indexSubsystem, IntakeSubsystem intakeSubsystem) {
        this.drive = driveSubsystem;
        this.index = indexSubsystem;
        this.intake = intakeSubsystem;
        // each subsystem used by the command must be passed into the
        // addRequirements() method (which takes a vararg of Subsystem)
        addRequirements(this.drive, this.index, this.intake);
    }

    private String fileName;

    @Override
    public void initialize() {
        fileName = Robot.AutoChooser.getSelected();
        if (fileName == null) {
            DriverStation.reportError("ReRun Record: FileName null", true);
            Finished = true;
        }
        if (fileName == Robot.noAuto) {
            DriverStation.reportWarning("ReRun Record: Auton Not Selected", true);
            Finished = true;
        }

        try {
            recordFile = new File("/home/lvuser/"+fileName);
            isNewFile = recordFile.createNewFile();
        } catch (IOException e) {
            DriverStation.reportError("FileSystem Error" + e.getMessage(), true);
        }
        if (isNewFile) {
            DriverStation.reportWarning("Auto Does Not Exist: " + fileName, true);
        }

        try {
            reader = new Scanner(recordFile);
        } catch (IOException e) {
            DriverStation.reportError("FileSystem Error" + e.getMessage(), true);
            Finished = true;
        }
    }

    @Override
    public void execute() {

        double lDrive = Double.parseDouble(reader.nextLine());
        double rDrive = Double.parseDouble(reader.nextLine());

        drive.set(ControlMode.Velocity, rDrive, lDrive);

    }

    @Override
    public boolean isFinished() {
        return Finished;
    }

    @Override
    public void end(boolean interrupted) {
            reader.close();
    }
}
