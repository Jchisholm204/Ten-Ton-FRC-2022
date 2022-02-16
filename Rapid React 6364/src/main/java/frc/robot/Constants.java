package frc.robot;

public final class Constants {
    
    //Talon Setting Constants
    public static final double kFalconMaxRPM = 6000; //Free Speed of Falcon FX ~ 6300
    public static final double kFalconEncoderUPR = 2048; //Encoder Ticks Per Revolution for the Falcon 500
    public static final int kPIDLoopIdx = 0;
    public static final int kTimeoutMs = 10;

    //Index Exclusive Constants
    public final class Index {
        public static final double bottomPHTriggerValue = 1000;
        public static final double topPHTriggerValue = 1000;
        public static final double intakePHTriggerValue = 1000;

        // Constants Used For the Index Color Sensor
        public final class Color{

            // The Maximum Value of RED to allow with a BLUE Ball
            public static final double redMax = 0.2;

            // The Minimum Value of RED Required in a RED ball
            public static final double redMin = 0.3;

            // The Maximum Value of BLUE to allow with a RED Ball
            public static final double blueMax = 0.2;

            // The Minimum Value of BLUE Required in a BLUE ball
            public static final double blueMin = 0.3;

            // The Minimum Proximity Value Required To Establish that the Color Sensor Is Currently Looking at A Ball
            public static final double ProxTrigger = 12;         }

        // Time Constants For Index Tasks
        public final class Timing {
            public static final double shoot = 2;
            public static final double outFront = 2;
            public static final double outBack = 4;
            public static final double index = 1;
        }
    }

    //Drive Exclusive Constants
    public static final class Drive {
        //Drive Characterization
        public static final double ksVolts = 0.22;
        public static final double kvVoltSecondsPerMeter = 1.98;
        public static final double kaVoltSecondsSquaredPerMeter = 0.2;

        public static final double kPDriveVel = 8.5;

        //Drive Kinematics
        public static final double kTrackWidthMeters = 0.69;

    }

    // Physical Map For Robot Ports
    public enum RobotMap {
        Controller_Main(0),
        Controller_Partner(1),

        //Drive Motor Ports (can)
        driveRM(0),
        driveRS(0),
        driveLM(0),
        driveLS(0),

        //Intake Motor Ports (can)
        intakeFront(02),
        intakeRear(03),

        //Index Motor Ports (can)
        indexTopMtr(01),
        indexBotMtr(00),
        indexFeedMtr(12),

        //Winch Motor
        winchMtr(13),

        //Index PhotoElectric Ports (Analog In)
        topIntakePE(0),
        botIntakePE(1),

        //Power Distribution Board (can)
        PDP(10);


        public final int port;
        RobotMap(int port){
            this.port = port;
        }
    }
    
}
