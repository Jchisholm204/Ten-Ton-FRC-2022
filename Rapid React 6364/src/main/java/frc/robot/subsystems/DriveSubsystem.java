package frc.robot.subsystems;

//Import Subsystem Module
import edu.wpi.first.wpilibj2.command.SubsystemBase;

//Import Motor Modules
import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.NeutralMode;
import com.ctre.phoenix.motorcontrol.can.TalonFX;

//Import Gyro Modules
import com.kauailabs.navx.frc.AHRS;
import edu.wpi.first.wpilibj.SPI;

//WPI
import edu.wpi.first.math.controller.PIDController;
import edu.wpi.first.math.controller.SimpleMotorFeedforward;
import edu.wpi.first.math.geometry.Rotation2d;
import edu.wpi.first.math.geometry.Pose2d;
import edu.wpi.first.math.kinematics.DifferentialDriveKinematics;
import edu.wpi.first.math.kinematics.DifferentialDriveOdometry;
import edu.wpi.first.math.kinematics.DifferentialDriveWheelSpeeds;
import edu.wpi.first.wpilibj.DriverStation;

//Import Robot Files
import frc.robot.utilities.InitializeTalon;
import frc.robot.Constants;

public class DriveSubsystem extends SubsystemBase{

    // Declare Drive Motors - driveRM = Drive Right Master // driveLS  = Drive Left Slave
    private TalonFX driveRM;
    private TalonFX driveRS;
    private TalonFX driveLM;
    private TalonFX driveLS;

    //Declare Sensors
    private AHRS gyro;

    //Declare Others
    private DifferentialDriveKinematics iKinematics;
    private DifferentialDriveWheelSpeeds iSpeeds;
    private DifferentialDriveOdometry iOdometry;
    private SimpleMotorFeedforward feedforward;
    private PIDController rightPID;
    private PIDController leftPID;

    public DriveSubsystem() {
        try {
            driveRM = new TalonFX(Constants.RobotMap.driveRM.port);
            driveRS = new TalonFX(Constants.RobotMap.driveRS.port);
            driveLM = new TalonFX(Constants.RobotMap.driveLM.port);
            driveLS = new TalonFX(Constants.RobotMap.driveLS.port);
        } catch (RuntimeException ex) {
            DriverStation.reportError("Error Starting Drive Motors: " + ex.getMessage(), true);
        }

        //Initialize Motors
        InitializeTalon.RightDrive(driveRM);
        InitializeTalon.RightDrive(driveRS);
        InitializeTalon.LeftDrive(driveLM);
        InitializeTalon.LeftDrive(driveLS);

        //Set Drive Brake Modes
        driveRM.setNeutralMode(NeutralMode.Coast);
        driveLM.setNeutralMode(NeutralMode.Coast);

        //Set Slave Motors To Follow Masters
        driveRS.follow(driveRM);
        driveLS.follow(driveLM);

        try {
            gyro = new AHRS(SPI.Port.kMXP);
        } catch (RuntimeException ex) {
            DriverStation.reportError("Error Starting NavX: " + ex.getMessage(), true);
        }
        gyro.reset();

        iOdometry = new DifferentialDriveOdometry(Rotation2d.fromDegrees(getAngle()));
        iKinematics = new DifferentialDriveKinematics(Constants.Drive.kTrackWidthMeters);
        iSpeeds = new DifferentialDriveWheelSpeeds(getLeftVelocity(), getRightVelocity());
        feedforward = new SimpleMotorFeedforward(Constants.Drive.ksVolts, Constants.Drive.kvVoltSecondsPerMeter, Constants.Drive.kaVoltSecondsSquaredPerMeter);
        rightPID = new PIDController(Constants.Drive.kPDriveVel, 0, 0);
        leftPID = new PIDController(Constants.Drive.kPDriveVel, 0, 0);
    }

    /**
     * Set Drive Motors Control Mode and Power
     * @param Mode CTRE TalonFX Control Mode
     * @param rightVal The Right Power Value
     * @param leftVal The Left Power Value
     */
    public void set(ControlMode Mode, double rightVal, double leftVal){
        driveRM.set(Mode, rightVal);
        driveLM.set(Mode, leftVal);
    }

    /**
     * Stops all Drivebase Movement
     */
    public void stop(){
        driveRM.set(ControlMode.PercentOutput, 0);
        driveLM.set(ControlMode.PercentOutput, 0);
    }

    /**
     * Get The Right Drive Position in Encoder Units (2408 per Revolute)
     * @return Current Position in Encoder Units
     */
    public double getRightPosition(){
        return driveRM.getSelectedSensorPosition();
    }

     /**
     * Get The Left Drive Position in Encoder Units (2408 per Revolute)
     * @return Current Position in Encoder Units
     */   
    public double getLeftPosition(){
        return driveLM.getSelectedSensorPosition();
    }

    /**
     * Get The Current Right Drive Velocity In Encoder Units
     * @return Encoder Units per 100ms
     */
    public double getRightVelocity(){
        return driveRM.getSelectedSensorVelocity();
    }

    /**
     * Get The Current Left Drive Velocity In Encoder Units
     * @return Encoder Units per 100ms
     */
    public double getLeftVelocity(){
        return driveLM.getSelectedSensorVelocity();
    }

    /**
     * Get The Right Drive RPM
     * @return Current Revolutions Per Minute
     */
    public double getRightRPM(){
        return driveRM.getSelectedSensorVelocity() / Constants.kFalconEncoderUPR * 600.0;
    }

    /**
     * Get The Left Drive RPM
     * @return Current Revolutions Per Minute
     */
    public double getLeftRPM(){
        return driveLM.getSelectedSensorVelocity() / Constants.kFalconEncoderUPR * 600.0;
    }

    /**
     * Reset DriveBase Sensors (true = reset, false = dont)
     * @param reset_encoders ?
     * @param reset_gyro ?
     */
    public void reset(boolean reset_encoders, boolean reset_gyro){
        if(reset_encoders){
            driveRM.setSelectedSensorPosition(0);
            driveLM.setSelectedSensorPosition(0);
        }
        if(reset_gyro){
            gyro.reset();
        }
    }

    /**
     * Get the NavX's Yaw Angle
     * @return Robot's Current Angle
     */
    public double getAngle(){
        return gyro.getYaw();
    }

    /**
     * Get the NavX's Heading
     * @return Accumulated Yaw Angle
     * Note: This Function can exeed values of 360
     */
    public double getHeading(){
        return gyro.getAngle();
    }

    /**
     * Get The Current Rate of change in the NavX's Yaw Axis
     * @return Robot's current turning rate
     */
    public double getAngleRate(){
        return gyro.getRate();
    }

    public SimpleMotorFeedforward getFeedForward(){
        return feedforward;
    }
    
    public PIDController getRightPID(){
        return rightPID;
    }

    public PIDController getLeftPID(){
        return leftPID;
    }

    public DifferentialDriveKinematics getKinematics(){
        return iKinematics;
    }

    /**
     * Returns Est Position of robot on feild.. in encoder units..?
     * @return
     */
    public Pose2d getGeoPos(){
        return iOdometry.getPoseMeters();
    }

    public void resetOdometry(Pose2d pose){
        reset(true, false);
        iOdometry.resetPosition(pose, Rotation2d.fromDegrees(getAngle()));
    }

    public DifferentialDriveWheelSpeeds getSpeeds(){
        return iSpeeds;
    }

    @Override
    public void periodic(){
        iOdometry.update(Rotation2d.fromDegrees(getAngle()), getLeftPosition(), getRightPosition());
    }
}
