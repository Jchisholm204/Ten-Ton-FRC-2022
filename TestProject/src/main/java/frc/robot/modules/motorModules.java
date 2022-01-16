package frc.robot.modules;

import com.ctre.phoenix.motorcontrol.can.TalonFX;

public class motorModules {
    public static double rtnVelocity(TalonFX iMotor, double kSensorUnitsPerRotation){
        double encoder_reading = iMotor.getSelectedSensorVelocity();
        double calc_rpm = encoder_reading / kSensorUnitsPerRotation * 600.0;
        return calc_rpm;
    }
}
