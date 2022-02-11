package frc.robot.utilities;

import com.ctre.phoenix.motorcontrol.FeedbackDevice;
import com.ctre.phoenix.motorcontrol.NeutralMode;
import com.ctre.phoenix.motorcontrol.can.TalonFX;
import com.ctre.phoenix.motorcontrol.can.TalonFXConfiguration;
import com.ctre.phoenix.motorcontrol.can.TalonSRX;

import frc.robot.Constants;

public class Talon {

    public static class Initialize {

        public static void GenericFX(final TalonFX iMotor, boolean inverted) {
            iMotor.configSelectedFeedbackSensor(FeedbackDevice.IntegratedSensor); //Set to use Internal Encoder
            iMotor.setSensorPhase(false); //Disable Sensor Phase (tuning)
            iMotor.setInverted(inverted); //Set Motor Inverted
            iMotor.configFactoryDefault(); //Use Factory Tune Settings
            //Output Settings
            iMotor.configNominalOutputForward(0);
            iMotor.configNominalOutputReverse(0);
            iMotor.configPeakOutputForward(1);
            iMotor.configPeakOutputReverse(-1);

            iMotor.setSelectedSensorPosition(0); // Reset Motor Encoder
        }

        public static void GenericSRX(final TalonSRX iMotor, boolean inverted) {
            iMotor.configSelectedFeedbackSensor(FeedbackDevice.None); //Set Encoder
            iMotor.setInverted(inverted); //Set Motor Inverted
            iMotor.configFactoryDefault(); //Use Factory Tune Settings
            //Output Settings
            iMotor.configNominalOutputForward(0);
            iMotor.configNominalOutputReverse(0);
            iMotor.configPeakOutputForward(1);
            iMotor.configPeakOutputReverse(-1);
        }

        public static void RightDrive(final TalonFX iMotor) {
            iMotor.configSelectedFeedbackSensor(FeedbackDevice.IntegratedSensor); //Set to use Internal Encoder
            iMotor.setSensorPhase(false); //Disable Sensor Phase (tuning)
            iMotor.setInverted(true); //Invert Motor
            iMotor.configFactoryDefault(); //Use Factory Tune Settings
            //Output Settings
            iMotor.configNominalOutputForward(0);
            iMotor.configNominalOutputReverse(0);
            iMotor.configPeakOutputForward(1);
            iMotor.configPeakOutputReverse(-1);

            iMotor.config_kF(Constants.kPIDLoopIdx, Constants.Drive.RightkF, Constants.kTimeoutMs);
            iMotor.config_kP(Constants.kPIDLoopIdx, Constants.Drive.RightkP, Constants.kTimeoutMs);
            iMotor.config_kI(Constants.kPIDLoopIdx, Constants.Drive.RightkI, Constants.kTimeoutMs);
            iMotor.config_kD(Constants.kPIDLoopIdx, Constants.Drive.RightkD, Constants.kTimeoutMs);

            iMotor.setSelectedSensorPosition(0); // Reset Motor Encoder
        }

        public static void LeftDrive(final TalonFX iMotor) {
            iMotor.configSelectedFeedbackSensor(FeedbackDevice.IntegratedSensor); //Set to use Internal Encoder
            iMotor.setSensorPhase(false); //Disable Sensor Phase (tuning)
            iMotor.setInverted(false); //Do Not Invert Motor
            iMotor.configFactoryDefault(); //Use Factory Tune Settings
            //Output Settings
            iMotor.configNominalOutputForward(0);
            iMotor.configNominalOutputReverse(0);
            iMotor.configPeakOutputForward(1);
            iMotor.configPeakOutputReverse(-1);

            iMotor.config_kF(Constants.kPIDLoopIdx, Constants.Drive.LeftkF, Constants.kTimeoutMs);
            iMotor.config_kP(Constants.kPIDLoopIdx, Constants.Drive.LeftkP, Constants.kTimeoutMs);
            iMotor.config_kI(Constants.kPIDLoopIdx, Constants.Drive.LeftkI, Constants.kTimeoutMs);
            iMotor.config_kD(Constants.kPIDLoopIdx, Constants.Drive.LeftkD, Constants.kTimeoutMs);

            iMotor.setSelectedSensorPosition(0); // Reset Motor Encoder
        }

        public static void Hang(final TalonFX iMotor, boolean inverted) {
            iMotor.configSelectedFeedbackSensor(FeedbackDevice.IntegratedSensor); //Set to use Internal Encoder
            iMotor.setSensorPhase(false); // Disable Sensor Phase (tuning)
            iMotor.setInverted(inverted); // Invert Motor?
            iMotor.configFactoryDefault(); // Use Factory Tune Settings
            //Output Settings
            iMotor.configNominalOutputForward(0);
            iMotor.configNominalOutputReverse(0);
            iMotor.configPeakOutputForward(1);
            iMotor.configPeakOutputReverse(-1);

            iMotor.config_kF(Constants.kPIDLoopIdx, 0.0500, Constants.kTimeoutMs);
            iMotor.config_kP(Constants.kPIDLoopIdx, 0.25, Constants.kTimeoutMs);
            iMotor.config_kI(Constants.kPIDLoopIdx, 0, Constants.kTimeoutMs);
            iMotor.config_kD(Constants.kPIDLoopIdx, 0, Constants.kTimeoutMs);
        }

        public static void Winch(final TalonFX iMotor, boolean inverted) {
            TalonFXConfiguration winchConfig = new TalonFXConfiguration(); //Create Motor Configuration
            winchConfig.primaryPID.selectedFeedbackSensor = FeedbackDevice.IntegratedSensor; //Set to use integrated Sensor
            winchConfig.slot0.kP = 2;
            winchConfig.slot0.kI = 0.0;
            winchConfig.slot0.kD =80.0;
            winchConfig.slot0.kF = 0.0505;
            winchConfig.closedloopRamp = 1;
            winchConfig.slot0.integralZone = 0;
            winchConfig.slot0.allowableClosedloopError = 0;
            winchConfig.motionAcceleration = 2000; //1000
            winchConfig.motionCruiseVelocity = 22000/*fs*//2; // to get half speed
            winchConfig.nominalOutputForward = 0.0;
            winchConfig.nominalOutputReverse = 0.0;
            winchConfig.peakOutputReverse = -1;
            winchConfig.peakOutputForward = 1;
            winchConfig.motionCurveStrength = 3;

            iMotor.configFactoryDefault(); //Reset Motor Configuration
            iMotor.configAllSettings(winchConfig); //Apply new Motor Configuration

            //iMotor.setSensorPhase(true); // Sensor Phase (tuning)
            iMotor.setInverted(inverted); // Invert Motor?

        }

        public static void Intake(final TalonSRX iMotor, boolean inverted) {
            iMotor.configSelectedFeedbackSensor(FeedbackDevice.None); //Set Encoder
            iMotor.setInverted(inverted); //Set Motor Invert
            iMotor.configFactoryDefault(); //Use Factory Tune Settings
            //Output Settings
            iMotor.configNominalOutputForward(0);
            iMotor.configNominalOutputReverse(0);
            iMotor.configPeakOutputForward(1);
            iMotor.configPeakOutputReverse(-1);

            iMotor.config_kF(Constants.kPIDLoopIdx, Constants.Intake.mkF, Constants.kTimeoutMs);
            iMotor.config_kP(Constants.kPIDLoopIdx, Constants.Intake.mkP, Constants.kTimeoutMs);
            iMotor.config_kI(Constants.kPIDLoopIdx, Constants.Intake.mkI, Constants.kTimeoutMs);
            iMotor.config_kD(Constants.kPIDLoopIdx, Constants.Intake.mkD, Constants.kTimeoutMs);
        }

        public static void Index(final TalonSRX iMotor, boolean inverted) {
            iMotor.configSelectedFeedbackSensor(FeedbackDevice.SoftwareEmulatedSensor); //Set Encoder
            iMotor.setInverted(inverted); //Set Motor Invert
            iMotor.configFactoryDefault(); //Use Factory Tune Settings
            //Output Settings
            iMotor.configNominalOutputForward(0);
            iMotor.configNominalOutputReverse(0);
            iMotor.configPeakOutputForward(1);
            iMotor.configPeakOutputReverse(-1);

            iMotor.config_kF(Constants.kPIDLoopIdx, Constants.Index.mkF, Constants.kTimeoutMs);
            iMotor.config_kP(Constants.kPIDLoopIdx, Constants.Index.mkP, Constants.kTimeoutMs);
            iMotor.config_kI(Constants.kPIDLoopIdx, Constants.Index.mkI, Constants.kTimeoutMs);
            iMotor.config_kD(Constants.kPIDLoopIdx, Constants.Index.mkD, Constants.kTimeoutMs);

            iMotor.setNeutralMode(NeutralMode.Brake); // Set Motor Neutral Mode To Hold

            //iMotor.setSelectedSensorPosition(0); // Reset Motor Encoder
        }

    }

    //Divide a Motors Encoder UPR by this number to get RPM
    public static final double rpmConverter = Constants.kFalconEncoderUPR * 600;
}
