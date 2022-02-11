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

        /**
         * Configuration For CTRE Talon FX Drive Motors
         * @param feedForward is the minimum motor power the motor needs to move
         * @return A Configuration Profile For The Drive Motors
         */
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

        /**
         * The Motor Configuration Profile for the Winch Motor
         * @return TalonFX Configuration Profile
         */
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

        /**
         * The Motor Configuration for the Intake Motors
         * @return Talon SRX Configuration Profile
         */
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

        /**
         * The Motor Configuration Profile for the Index Motors
         * @return Talon SRX Configuration Profile
         */
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

        /**
         * Applies The Right Drive Configuration to a Motor
         * @param iMotor TalonFX Motor
         */
        public static void RightDrive(final TalonFX iMotor) {
            iMotor.configFactoryDefault(); // Set to Factory Tune Before Applying any kind of user Configuration
            iMotor.configAllSettings(DriveConfiguration(0.050));

            iMotor.setNeutralMode(NeutralMode.Brake);

            iMotor.setInverted(true); // Invert Motor

            iMotor.setSelectedSensorPosition(0); // Reset Motor Encoder
        }

        /**
         * Applies The Left Drive Configuration to a Motor
         * @param iMotor TalonFX Motor
         */
        public static void LeftDrive(final TalonFX iMotor) {
            iMotor.configFactoryDefault(); // Set to Factory Tune Before Applying any kind of user Configuration
            iMotor.configAllSettings(DriveConfiguration(0.050));

            iMotor.setNeutralMode(NeutralMode.Brake);

            iMotor.setInverted(false); // Don't Invert Motor

            iMotor.setSelectedSensorPosition(0); // Reset Motor Encoder
        }

        /**
         * Applies the Motor Configuration for the Winch Motor
         * @param iMotor TalonFX Motor
         * @param inverted Direction Inversion for the Motor (true=inverted)
         */
        public static void Winch(final TalonFX iMotor, boolean inverted) {

            iMotor.configFactoryDefault(); //Reset Motor Configuration before applying any kind of user configuration
            iMotor.configAllSettings(WinchConfiguration()); //Apply new Motor Configuration

            iMotor.setNeutralMode(NeutralMode.Brake);

            //iMotor.setSensorPhase(true); // Sensor Phase (tuning) // Not needed for TalonFX Integrated Sensors
            iMotor.setInverted(inverted); // Invert Motor?

        }

        /**
         * Applies the Motor Configuration for the Intake Motors
         * @param iMotor TalonSRX Motor
         * @param inverted Direction Inversion for the Motor (true=inverted)
         */
        public static void Intake(final TalonSRX iMotor, boolean inverted) {

            iMotor.configFactoryDefault(); //Reset Motor Configuration before applying any kind of user configuration
            iMotor.configAllSettings(IntakeConfiguration()); //Apply new Motor Configuration

            iMotor.setNeutralMode(NeutralMode.Coast); // Set Motor to Break When Current Not Applied

            //iMotor.setSensorPhase(true); // Sensor Phase (tuning) // Not needed for TalonFX Integrated Sensors
            iMotor.setInverted(inverted); // Invert Motor?
        }

        /**
         * Applies the Motor Configuration for the Index Motors
         * @param iMotor TalonSRX Motor
         * @param inverted Direction Inversion for the Motor (true=inverted)
         */
        public static void Index(final TalonSRX iMotor, boolean inverted) {

            iMotor.configFactoryDefault(); //Reset Motor Configuration before applying any kind of user configuration
            iMotor.configAllSettings(IndexConfiguration()); //Apply new Motor Configuration

            iMotor.setNeutralMode(NeutralMode.Brake); // Set Motor to break when current not applied
            // Useful for Holding Balls in the Index (Not letting them roll down)

            //iMotor.setSensorPhase(true); // Sensor Phase (tuning) // Not needed for TalonFX Integrated Sensors
            iMotor.setInverted(inverted); // Invert Motor?
        }

    }

    //Divide a Motors Encoder UPR by this number to get RPM
    public static final double rpmConverter = Constants.kFalconEncoderUPR * 600;
}
