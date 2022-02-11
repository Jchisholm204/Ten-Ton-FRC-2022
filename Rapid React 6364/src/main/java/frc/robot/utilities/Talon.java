package frc.robot.utilities;

import com.ctre.phoenix.motorcontrol.FeedbackDevice;
import com.ctre.phoenix.motorcontrol.NeutralMode;
import com.ctre.phoenix.motorcontrol.can.TalonFX;
import com.ctre.phoenix.motorcontrol.can.TalonFXConfiguration;
import com.ctre.phoenix.motorcontrol.can.TalonSRX;

import com.ctre.phoenix.motorcontrol.can.TalonSRXConfiguration;
import frc.robot.Constants;

public class Talon {

    public static class Initialize {

        private static TalonFXConfiguration DriveConfiguration(double feedForward){
            TalonFXConfiguration configuration = new TalonFXConfiguration();

            configuration.primaryPID.selectedFeedbackSensor = FeedbackDevice.IntegratedSensor; //TalonFX uses Integrated Motor Sensor
            configuration.slot0.kP = 0.0; // Standard PID kP - used for MagicMotion movement
            configuration.slot0.kI = 0.0; // Standard PID kI - used for MagicMotion movement
            configuration.slot0.kD = 0.0; // Standard PID kD - used for MagicMotion movement
            configuration.slot0.kF = feedForward; // kF - Feed Forward Value - The minimum motor power you have to apply to move the motor

            configuration.slot0.integralZone = 0;
            configuration.slot0.allowableClosedloopError = 0;
            configuration.closedloopRamp = 0;

            configuration.motionAcceleration = 2000; // Maximum Acceleration for MagicMotion
            configuration.motionCruiseVelocity = 22000/*fs*/; // Maximum Speed (in encoder units / 100ms) for Magic Motion

            configuration.nominalOutputForward = 0.0;
            configuration.nominalOutputReverse = 0.0;
            configuration.peakOutputForward = 1.0;
            configuration.peakOutputReverse = -1.0;

            configuration.motionCurveStrength = 3; // Magic Motion Curve Strength (read the docs)

            return configuration; //Return the Motor Configuration
        }

        private static TalonFXConfiguration WinchConfiguration(){

            TalonFXConfiguration configuration = new TalonFXConfiguration(); //Set up new motor configuration

            configuration.primaryPID.selectedFeedbackSensor = FeedbackDevice.IntegratedSensor; //TalonFX uses Integrated Motor Sensor
            configuration.slot0.kP = 2.0; // Standard PID kP - used for MagicMotion movement
            configuration.slot0.kI = 0.0; // Standard PID kI - used for MagicMotion movement
            configuration.slot0.kD = 80.0; // Standard PID kD - used for MagicMotion movement
            configuration.slot0.kF = 0.0505; // kF - Feed Forward Value - The minimum motor power you have to apply to move the motor

            configuration.slot0.integralZone = 0;
            configuration.slot0.allowableClosedloopError = 0;
            configuration.closedloopRamp = 0;

            configuration.motionAcceleration = 2000; // Maximum Acceleration for MagicMotion
            configuration.motionCruiseVelocity = 22000/*fs*/ / 4 /*quarter speed*/; // Maximum Speed (in encoder units / 100ms) for Magic Motion

            configuration.nominalOutputForward = 0.0;
            configuration.nominalOutputReverse = 0.0;
            configuration.peakOutputForward = 1.0;
            configuration.peakOutputReverse = -1.0;

            configuration.motionCurveStrength = 3; // Magic Motion Curve Strength (read the docs)

            return configuration; //Return the Motor Configuration
        }

        private static TalonSRXConfiguration IntakeConfiguration(){
            TalonSRXConfiguration configuration = new TalonSRXConfiguration();

            configuration.primaryPID.selectedFeedbackSensor = FeedbackDevice.None;
            configuration.slot0.kP = 0.0; // Standard PID kP - used for MagicMotion movement
            configuration.slot0.kI = 0.0; // Standard PID kI - used for MagicMotion movement
            configuration.slot0.kD = 0.0; // Standard PID kD - used for MagicMotion movement
            configuration.slot0.kF = 0.0505; // kF - Feed Forward Value - The minimum motor power you have to apply to move the motor

            configuration.slot0.integralZone = 0;
            configuration.slot0.allowableClosedloopError = 0;
            configuration.closedloopRamp = 0;

            configuration.motionAcceleration = 2000; // Maximum Acceleration for MagicMotion
            configuration.motionCruiseVelocity = 22000/*fs*/; // Maximum Speed (in encoder units / 100ms) for Magic Motion

            configuration.nominalOutputForward = 0.0;
            configuration.nominalOutputReverse = 0.0;
            configuration.peakOutputForward = 1.0;
            configuration.peakOutputReverse = -1.0;

            configuration.motionCurveStrength = 3; // Magic Motion Curve Strength (read the docs)

            return configuration; //Return the Motor Configuration
        }

        private static TalonSRXConfiguration IndexConfiguration(){
            TalonSRXConfiguration configuration = new TalonSRXConfiguration();

            configuration.primaryPID.selectedFeedbackSensor = FeedbackDevice.None;
            configuration.slot0.kP = 0.0; // Standard PID kP - used for MagicMotion movement
            configuration.slot0.kI = 0.0; // Standard PID kI - used for MagicMotion movement
            configuration.slot0.kD = 0.0; // Standard PID kD - used for MagicMotion movement
            configuration.slot0.kF = 0.0505; // kF - Feed Forward Value - The minimum motor power you have to apply to move the motor

            configuration.slot0.integralZone = 0;
            configuration.slot0.allowableClosedloopError = 0;
            configuration.closedloopRamp = 0;

            configuration.motionAcceleration = 2000; // Maximum Acceleration for MagicMotion
            configuration.motionCruiseVelocity = 22000/*fs*/; // Maximum Speed (in encoder units / 100ms) for Magic Motion

            configuration.nominalOutputForward = 0.0;
            configuration.nominalOutputReverse = 0.0;
            configuration.peakOutputForward = 1.0;
            configuration.peakOutputReverse = -1.0;

            configuration.motionCurveStrength = 3; // Magic Motion Curve Strength (read the docs)

            return configuration; //Return the Motor Configuration
        }

        public static void RightDrive(final TalonFX iMotor) {
            iMotor.configFactoryDefault(); // Set to Factory Tune Before Applying any kind of user Configuration
            iMotor.configAllSettings(DriveConfiguration(0.050));
            iMotor.setInverted(true); // Invert Motor

            iMotor.setSelectedSensorPosition(0); // Reset Motor Encoder
        }

        public static void LeftDrive(final TalonFX iMotor) {
            iMotor.configFactoryDefault(); // Set to Factory Tune Before Applying any kind of user Configuration
            iMotor.configAllSettings(DriveConfiguration(0.050));
            iMotor.setInverted(false); // Don't Invert Motor

            iMotor.setSelectedSensorPosition(0); // Reset Motor Encoder
        }

        public static void Winch(final TalonFX iMotor, boolean inverted) {

            iMotor.configFactoryDefault(); //Reset Motor Configuration before applying any kind of user configuration
            iMotor.configAllSettings(WinchConfiguration()); //Apply new Motor Configuration

            //iMotor.setSensorPhase(true); // Sensor Phase (tuning) // Not needed for TalonFX Integrated Sensors
            iMotor.setInverted(inverted); // Invert Motor?

        }

        public static void Intake(final TalonSRX iMotor, boolean inverted) {

            iMotor.configFactoryDefault(); //Reset Motor Configuration before applying any kind of user configuration
            iMotor.configAllSettings(IntakeConfiguration()); //Apply new Motor Configuration

            //iMotor.setSensorPhase(true); // Sensor Phase (tuning) // Not needed for TalonFX Integrated Sensors
            iMotor.setInverted(inverted); // Invert Motor?
        }

        public static void Index(final TalonSRX iMotor, boolean inverted) {

            iMotor.configFactoryDefault(); //Reset Motor Configuration before applying any kind of user configuration
            iMotor.configAllSettings(IndexConfiguration()); //Apply new Motor Configuration

            //iMotor.setSensorPhase(true); // Sensor Phase (tuning) // Not needed for TalonFX Integrated Sensors
            iMotor.setInverted(inverted); // Invert Motor?
        }

    }

    //Divide a Motors Encoder UPR by this number to get RPM
    public static final double rpmConverter = Constants.kFalconEncoderUPR * 600;
}
