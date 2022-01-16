package frc.robot;

public final class Constants {

    //Falcon FX 500 constants
    public static final double kFalconMaxRpm = 6000;
    public static final double kEncoderUnitsPerRevo = 2048;
    public static final int kDriveSlotIdx = 0;
    public static final int kTimeoutMs = 10;

    //Flywheel Constants
    public static final double kFlywheelkP = 0;
    public static final double kFlywheelkI = 0;
    public static final double kFlywheelkD = 0;
    public static final double kFlywheelkF = 0.05;

    //Drive Constants
    public static final double kRightDrivekP = 0;
    public static final double kRightDrivekI = 0;
    public static final double kRightDrivekD = 0;
    public static final double kRightDrivekF = 0;

    public static final double kLeftDrivekP = 0;
    public static final double kLeftDrivekI = 0;
    public static final double kLeftDrivekD = 0;
    public static final double kLeftDrivekF = 0;
    

    public enum RobotMap {
        CONTROLLER_MAIN(0),
        CONTROLLER_PARTNER(1),

        DRIVE_RM(0),
        DRIVE_RS(0),    
        DRIVE_LM(0),
        DRIVE_LS(0),
        INDEX_TOP(0),
        INDEX_BOT(0),
        INTAKE_MTR(0),
        FLYWHEEL_MOTOR(0);

        public final int value;
        RobotMap(int value){
            this.value = value;
        }
    }
}
