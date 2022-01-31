package frc.robot.ReRun;

import edu.wpi.first.wpilibj.DriverStation;
import edu.wpi.first.wpilibj2.command.CommandBase;
import frc.robot.subsystems.*;
import frc.robot.Robot;

import java.io.*;


public class RecordCommand extends CommandBase {
    private final DriveSubsystem drive;
    private final IndexSubsystem index;
    private final IntakeSubsystem intake;

    private File f;
    private PrintWriter writer;
    private boolean isNewFile;

    private boolean Finished = false;

    public RecordCommand(DriveSubsystem driveSubsystem, IndexSubsystem indexSubsystem, IntakeSubsystem intakeSubsystem) {
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
        /*
        fileName = Robot.AutoChooser.getSelected();
        if (fileName == null) {
            DriverStation.reportError("ReRun Record: FileName null", true);
            Finished = true;
        }
        if (fileName == Robot.noAuto) {
            DriverStation.reportWarning("ReRun Record: Auton Not Selected", true);
            Finished = true;
        }*/

        fileName = "TestAuton.txt";

        try {
            f = new File("/home/lvuser/"+fileName);
            isNewFile = f.createNewFile();
        } catch (IOException e) {
            DriverStation.reportError("FileSystem Error" + e.getMessage(), true);
        }


        if (!isNewFile) {
            DriverStation.reportWarning("You are about to OverWrite File: " + fileName, true);
        }

        try {
            writer = new PrintWriter(f);
        } catch (FileNotFoundException e) {
            DriverStation.reportError("File Error " + e.getMessage(), true);
        }
    }

    @Override
    public void execute() {

        writer.printf("%b\n", drive.getLeftVelocity());
        writer.printf("%b\n", drive.getRightVelocity());

    }

    @Override
    public boolean isFinished() {
        return Finished;
    }

    @Override
    public void end(boolean interrupted) {
        writer.close();
    }
}
