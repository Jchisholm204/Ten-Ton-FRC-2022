package frc.robot.utilities;

import com.ctre.phoenix.motorcontrol.FeedbackDevice;
import com.ctre.phoenix.motorcontrol.can.TalonFX;

import frc.robot.Constants;

public class TalonUtils {
    public static void initGenericFalcon(final TalonFX iMotor, boolean inverted){
        iMotor.configSelectedFeedbackSensor(FeedbackDevice.IntegratedSensor, 0, Constants.kTimeoutMs);
        iMotor.setSensorPhase(false);
        iMotor.setInverted(inverted);

        iMotor.configFactoryDefault();
        //Reset Encoder
        iMotor.setSelectedSensorPosition(0);
    }
    public static void initRightDriveFalcon(final TalonFX iMotor){
        iMotor.configSelectedFeedbackSensor(FeedbackDevice.IntegratedSensor, 0, Constants.kTimeoutMs);
        iMotor.setSensorPhase(false);
        //Set Motor Invert
        iMotor.setInverted(true);
        //Reset Encoder
        iMotor.setSelectedSensorPosition(0);
        //Config PID
        iMotor.config_kF(0, Constants.kRightDrivekF, Constants.kTimeoutMs);
        iMotor.config_kP(0, Constants.kRightDrivekP, Constants.kTimeoutMs);
        iMotor.config_kI(0, Constants.kRightDrivekI, Constants.kTimeoutMs);
        iMotor.config_kD(0, Constants.kRightDrivekD, Constants.kTimeoutMs);
    }
    public static void initLeftDriveFalcon(final TalonFX iMotor){
        iMotor.configSelectedFeedbackSensor(FeedbackDevice.IntegratedSensor, 0, Constants.kTimeoutMs);
        iMotor.setSensorPhase(false);
        //Set Invert
        iMotor.setInverted(false);
        //Reset Encoder
        iMotor.setSelectedSensorPosition(0);
        //Config PID
        iMotor.config_kF(0, Constants.kLeftDrivekF, Constants.kTimeoutMs);
        iMotor.config_kP(0, Constants.kLeftDrivekP, Constants.kTimeoutMs);
        iMotor.config_kI(0, Constants.kLeftDrivekI, Constants.kTimeoutMs);
        iMotor.config_kD(0, Constants.kLeftDrivekD, Constants.kTimeoutMs);
    }
    public static double rtnVelocity(TalonFX iMotor, double kSensorUnitsPerRotation){
        double encoder_reading = iMotor.getSelectedSensorVelocity();
        double calc_rpm = encoder_reading / kSensorUnitsPerRotation * 600.0;
        return calc_rpm;
    }
}
