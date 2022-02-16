package frc.robot.commands;

//Motor Dependencies
import com.ctre.phoenix.motorcontrol.ControlMode;
import edu.wpi.first.wpilibj.DriverStation;
import edu.wpi.first.wpilibj.GenericHID;
import edu.wpi.first.wpilibj.util.Color;

//Import WPI
import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.CommandBase;

//Import Robot Files
import frc.robot.Constants;
import frc.robot.subsystems.IndexSubsystem;
import frc.robot.Robot;

import java.sql.Time;

public class OpIndex extends CommandBase {
    private final IndexSubsystem indexer;
    private double WaitSaveTime1;
    private double WaitSaveTime2;
    private double WaitTime2;
    private boolean invalidColor;

    //Set Team Color for Ball Color Detection
    private static final IndexSubsystem.ballColor teamColor = IndexSubsystem.ballColor.UNDETERMINED;


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
        SmartDashboard.putNumber("Color R", indexer.getColor().red);
        SmartDashboard.putNumber("Color G", indexer.getColor().green);
        SmartDashboard.putNumber("Color B", indexer.getColor().blue);



        // Shooting | If Main Driver Wants to Shoot, or if Shoot is currently running: Wait and Run Shoot Program
        if(Timer.getFPGATimestamp() < (WaitSaveTime1 + Constants.Index.Timing.shoot) || Robot.robotContainer.master.getRightBumper()){
            // Shoot
            indexer.shoot();
            //Only Update WaitTime if Shoot Button Pressed
            if(Robot.robotContainer.master.getRightBumper()) {
                WaitSaveTime1 = Timer.getFPGATimestamp();
            }
        }
        else { // Indexing | When Not Shooting: Run the Indexing Program

            // Wait | If Invalid Color: Wait for Controller Input || If Valid Color: Wait for Running Program to Finish
            if (Timer.getFPGATimestamp() < (WaitSaveTime2 + WaitTime2)) {

                // Invalid Color Function is Triggered When Color Sensor Detects A Color that is NOT the team Color
                if(invalidColor/*is detected*/){

                    // Partner Presses UP on dPAD: Robot Error: Index The Ball as Normal
                    if(Robot.robotContainer.partner.getPOV() == 0){
                        indexer.runCodex(1,1);
                        WaitTime2 = Constants.Index.Timing.index;
                        WaitSaveTime2 = Timer.getFPGATimestamp();
                        invalidColor = false;
                    }

                    // Partner Presses RIGHT on dPAD: Remove The Ball From The Robot Through The Front Intake
                    else if(Robot.robotContainer.partner.getPOV() == 90){
                        indexer.stop();
                        indexer.setFeed(ControlMode.PercentOutput, 1);
                        if(indexer.getCodex() < 2){
                            indexer.setBot(ControlMode.PercentOutput, -1);
                        }
                        WaitTime2 = Constants.Index.Timing.outFront;
                        WaitSaveTime2 = Timer.getFPGATimestamp();
                        invalidColor = false;
                    }

                    // Partner Presses Left on dPAD: Remove The Ball From The Robot Through The Rear Intake
                    else if(Robot.robotContainer.partner.getPOV() == 290){
                        indexer.stop();
                        indexer.setFeed(ControlMode.PercentOutput, -1);
                        if(indexer.getCodex() < 2){
                            indexer.setBot(ControlMode.PercentOutput, 1);
                        }
                        WaitTime2 = Constants.Index.Timing.outBack;
                        WaitSaveTime2 = Timer.getFPGATimestamp();
                        invalidColor = false;
                    }

                    // ELSE: (Invalid Color Detection not Tripped) Wait For The Ongoing Task To Finish With Its Given Delay
                }
            }

            // Color Sensing | When Not Shooting OR Other Task Running

            // Color Proximity Check: Only Check The Color of The Ball IF there is a ball to check
            else if(indexer.getColorProximity() > Constants.Index.Color.ProxTrigger) {

                // Ball Color == Team Color: Index the Ball
                if (indexer.getBallColor() == teamColor) {
                    invalidColor = false;
                    indexer.runCodex(1, 1);
                    WaitTime2 = 4;
                    WaitSaveTime2 = Timer.getFPGATimestamp();
                }

                // Robot Unable to Determine Ball Color: Print Error To Terminal and Let Partner Driver Decide What to Do
                else if(indexer.getBallColor() == IndexSubsystem.ballColor.UNDETERMINED){
                    System.out.println("Undetermined Color Registered: " + indexer.getColor());
                    Robot.robotContainer.master.setRumble(GenericHID.RumbleType.kLeftRumble, 0.3);
                    invalidColor = true;
                    WaitTime2 = Timer.getFPGATimestamp() * 1000;
                    WaitSaveTime2 = Timer.getFPGATimestamp();
                }

                // Ball Color != Team Color: Let Partner Driver Decide What to do
                else{
                    Robot.robotContainer.master.setRumble(GenericHID.RumbleType.kLeftRumble, 0.3);
                    invalidColor = true;
                    WaitTime2 = Timer.getFPGATimestamp() * 1000;
                    WaitSaveTime2 = Timer.getFPGATimestamp();
                }
            }

            // Not Running Task AND No Ball Detected By Color Sensor: Stop Indexer and Run Feed Motor (intake mode)
            else{
                indexer.stop();
                indexer.setFeed(ControlMode.PercentOutput, 0.5);
            }
        }
    }

    @Override
    public void end(boolean interrupted){
        indexer.stop();
        indexer.stopFeed();
    }

    @Override
    public boolean isFinished(){
        return false;
    }
}
