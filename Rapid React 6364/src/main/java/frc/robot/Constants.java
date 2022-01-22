package frc.robot;

import edu.wpi.first.math.kinematics.DifferentialDriveKinematics;

public final class Constants {
    
    //Talon Setting Constants
    public static final double kFalconMaxRPM = 6000; //Free Speed of Falcon FX ~ 6300
    public static final double kFalconEncoderUPR = 2048; //Encoder Ticks Per Revolution for the Falcon 500
    public static final int kPIDLoopIdx = 0;
    public static final int kTimeoutMs = 10;

    //Intake Constants
    public final class Intake {
        public static final double mkP = 0;
        public static final double mkI = 0;
        public static final double mkD = 0;
        public static final double mkF = 0.0505;
    }

    public final class Index {
        public static final double mkP = 0;
        public static final double mkI = 0;
        public static final double mkD = 0;
        public static final double mkF = 0.0505;
    }

    //Drive Constants
    public static final class Drive {
        //Right Side Motor Constants
        public static final double RightkP = 0;
        public static final double RightkI = 0;
        public static final double RightkD = 0;
        public static final double RightkF = 0.0500;
        //Left Side Motor Constants
        public static final double LeftkP = 0;
        public static final double LeftkI = 0;
        public static final double LeftkD = 0;
        public static final double LeftkF = 0.0456;
        //Drive Characterization
        public static final double ksVolts = 0.22;
        public static final double kvVoltSecondsPerMeter = 1.98;
        public static final double kaVoltSecondsSquaredPerMeter = 0.2;

        public static final double kPDriveVel = 8.5;

        //Drive Kinematics
        public static final double kWheelDiameterMeters = 0.1905;
        public static final double kTrackWidthMeters = 0.69;
        public static final DifferentialDriveKinematics kDriveKinematics = new DifferentialDriveKinematics(kTrackWidthMeters);

        public static final double kMaxSpeedMetersPerSecond = 3;
        public static final double kMaxSpeedMetersPerSecondSquared = 3;

    }

    public enum RobotMap {
        Controller_Main(0),
        Controller_Partner(1),

        //Drive Motor Ports (can)
        driveRM(0),
        driveRS(0),
        driveLM(0),
        driveLS(0),

        //Intake Motor Ports (can)
        intakeFront(0),
        intakeRear(0),

        //Index Motor Ports (can)
        indexTopMtr(0),
        indexBotMtr(0),

        //Index PhotoElectric Ports (Analog In)
        topIntakePE(0),
        botIntakePE(1);


        public final int port;
        RobotMap(int port){
            this.port = port;
        }
    }
    
}
