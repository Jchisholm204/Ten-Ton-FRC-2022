package frc.robot.systems;

import com.ctre.phoenix.motorcontrol.can.TalonFX;
import frc.robot.utilities.TalonUtils;
import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.NeutralMode;
import com.kauailabs.navx.frc.AHRS;
import frc.robot.Constants;
import edu.wpi.first.wpilibj.DriverStation;
import edu.wpi.first.wpilibj.SPI;

public class Drive {
    //Declare Drive Motors
    private TalonFX driveRM;
    private TalonFX driveRS;
    private TalonFX driveLM;
    private TalonFX driveLS;
    //Declare Sensors
    private AHRS gyro;
    public Drive(){
        try{
            driveRM = new TalonFX(Constants.RobotMap.DRIVE_RM.value);
            driveRS = new TalonFX(Constants.RobotMap.DRIVE_RS.value);
            driveLM = new TalonFX(Constants.RobotMap.DRIVE_LM.value);
            driveLS = new TalonFX(Constants.RobotMap.DRIVE_LS.value);
        } catch(RuntimeException ex){
            DriverStation.reportError("Error Starting TalonFX: " + ex.getMessage(), true);
        }

        //Initialize Motors
        TalonUtils.initRightDriveFalcon(driveRM);
        TalonUtils.initRightDriveFalcon(driveRS);
        TalonUtils.initLeftDriveFalcon(driveLM);
        TalonUtils.initLeftDriveFalcon(driveLS);

        driveRM.setNeutralMode(NeutralMode.Brake);
        driveLM.setNeutralMode(NeutralMode.Brake);

        driveRS.follow(driveRM);
        driveLS.follow(driveLM);

        //Init Gyro
        try{
            gyro = new AHRS(SPI.Port.kMXP);
        } catch(RuntimeException ex){
            DriverStation.reportError("Error Starting NavX:" + ex.getMessage(), true);
        }

        reset_drive();


    }
    public void reset_drive(){
        gyro.reset();
        driveRM.setSelectedSensorPosition(0);
        driveLM.setSelectedSensorPosition(0);
    }

    private static double expoDrive(double joyVal, double joyMax, double d, int deadZone, int motorMin){
        double joySign;
        joyMax = joyMax - deadZone;
        double joyLive = Math.abs(joyVal) - deadZone;
        if(joyVal > 0){joySign = 1;}
        else if(joyVal < 0){joySign = -1;}
        else{joySign = 0;}
        double power = joySign * (motorMin + ((joyMax - motorMin) * (Math.pow(joyLive, d) / Math.pow(joyMax, d))));
        return power;
    }
    
    public void opDrive(double joyTurn, double joyDrive){
        double Xval = expoDrive(joyTurn, 100, 1.3, 8, 5);
        double Yval = expoDrive(joyDrive, 100, 1.3, 8, 5);
        driveRM.set(ControlMode.PercentOutput, (Yval-Xval)/100);
        driveLM.set(ControlMode.PercentOutput, (Yval+Xval)/100);
    }

}
