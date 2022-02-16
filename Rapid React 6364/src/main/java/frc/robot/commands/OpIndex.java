package frc.robot.commands;

//Motor Dependencies
import com.ctre.phoenix.motorcontrol.ControlMode;
import edu.wpi.first.wpilibj.DriverStation;
import edu.wpi.first.wpilibj.util.Color;

//Import WPI
import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.CommandBase;

//Import Robot Files
import frc.robot.Constants;
import frc.robot.subsystems.IndexSubsystem;
import frc.robot.Robot;

public class OpIndex extends CommandBase {
    private final IndexSubsystem indexer;
    private double WaitSaveTime1;
    private double WaitSaveTime2;
    //
    private boolean intakeDirectionBack;

    private final double shotTime = 2; // Seconds To Wait While Shooting
    private final double outTakeTime = 1;
    //Set Team Color for Ball Color Detection
    private static final IndexSubsystem.ballColor teamColor = IndexSubsystem.ballColor.UNDETERMINED;

    //initialize the codex to track balls inside the intake
    private static int codex = 0;


    public OpIndex(final IndexSubsystem indexSubSys){
        indexer = indexSubSys;
        addRequirements(indexer);
    }
    
    @Override
    public void initialize(){
        indexer.stop();
    }

    @Override
    public void execute(){
        SmartDashboard.putNumber("Codex", indexer.getCodex());
        SmartDashboard.putBoolean("topPE", indexer.getTopSensor());
        SmartDashboard.putBoolean("botPE", indexer.getBotSensor());

        SmartDashboard.putNumber("Color Proximity", indexer.getColorProximity());
        SmartDashboard.putNumber("Color IR", indexer.getColorIR());
        SmartDashboard.putNumber("Color R", indexer.getColor().red);
        SmartDashboard.putNumber("Color G", indexer.getColor().green);
        SmartDashboard.putNumber("Color B", indexer.getColor().blue);



        // Shooting | Running Index \\
        if(Timer.getFPGATimestamp() < (WaitSaveTime1 + shotTime)){
            //Do Nothing
            //Wait For Shot to finish
        }
        else if(Robot.robotContainer.master.getRightBumperPressed()){
            indexer.shoot();
            WaitSaveTime1 = Timer.getFPGATimestamp();
        }
        else if(Robot.robotContainer.master.getLeftBumper()){
            indexer.setTop(ControlMode.PercentOutput, -0.5);
            indexer.setBot(ControlMode.PercentOutput, -0.5);
        }
        else {
            if (Timer.getFPGATimestamp() < (WaitSaveTime2 + outTakeTime)) {

            }
            else {
                if (indexer.getBallColor() == IndexSubsystem.ballColor.UNDETERMINED){
                    System.out.println("Undetermined Ball Color");
                    System.out.println(indexer.getColor().red + " " + indexer.getColor().green + " " + indexer.getColor().blue);
                }
                else if (indexer.getBallColor() != teamColor && codex != 2 && indexer.getBallColor() != IndexSubsystem.ballColor.noBall) {
                    //Send it Out the Other Way
                    if (intakeDirectionBack) {
                        indexer.setBot(ControlMode.PercentOutput, -1);
                    } else {
                        indexer.setFeed(ControlMode.PercentOutput, -1);
                    }
                    WaitSaveTime2 = Timer.getFPGATimestamp();
                };

                if (indexer.getIntakeSensor()) {
                    intakeDirectionBack = true;
                } else if (indexer.getColorProximity() > Constants.Index.colorProximityTriggerValue) {
                    intakeDirectionBack = false;
                }

                if (indexer.getTopSensor() && codex == 0) {
                    codex = 1;
                };
                if (indexer.getBotSensor() && codex == 1) {
                    codex = 2;
                };

                if (codex == 2) {
                    indexer.setTop(ControlMode.PercentOutput, 0);
                    indexer.setBot(ControlMode.PercentOutput, 0);
                } else if (codex == 1) {
                    indexer.setTop(ControlMode.PercentOutput, 0);
                    indexer.setBot(ControlMode.PercentOutput, 1);
                } else if (codex == 0) {
                    indexer.setTop(ControlMode.PercentOutput, 1);
                    indexer.setBot(ControlMode.PercentOutput, 1);
                }
            }
        }
    }

    @Override
    public void end(boolean interrupted){
        indexer.stop();
    }

    @Override
    public boolean isFinished(){
        return false;
    }
}
