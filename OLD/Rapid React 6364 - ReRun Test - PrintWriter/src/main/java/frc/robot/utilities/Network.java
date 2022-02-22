package frc.robot.utilities;
import edu.wpi.first.networktables.NetworkTableEntry;
import edu.wpi.first.networktables.NetworkTableInstance;


public class Network {
    public static class Jetson {
        private static NetworkTableInstance table = null;
        
        /**
         * Return a Network Table Entry
         * @param entry The Entry to Return
         * @return The Network Table Entry
         */
        private static NetworkTableEntry getEntry(String entry){
            if (table == null){
                table = NetworkTableInstance.getDefault();
            }
            return table.getTable("jetson").getEntry(entry);
        }

        public static boolean ping(){
            return getEntry("ping").getBoolean(false);
        }
    }
    public static class Limelight{

        private static NetworkTableInstance table = null;

        /**
         * Return a Network Table Entry
         * @param entry The Entry to Return
         * @return The Network Table Entry
         */
        private static NetworkTableEntry getEntry(String entry){
            if (table == null){
                table = NetworkTableInstance.getDefault();
            }
            return table.getTable("limelight").getEntry(entry);
        }

        /**
         * Get if the Limelight has a Target
         * @return true if it has a target
         */
        public boolean hasTarget(){
            return getEntry("tv").getDouble(0) == 1;
        }

        /**
         * Get the LimeLights Target's Current X Position
         * @return The Current X readout
         */
        public double getTargetX(){
            return getEntry("tx").getDouble(0.00);
        }

        /**
         * Get the LimeLights Target's Current Y Position
         * @return The Current Y Readout
         */
        public double getTargetY(){
            return getEntry("ty").getDouble(0.00);
        }

        /**
         * Get the Current Target Area of the Target
         * @return Target Area (0% of image to 100% of image)
         */
        public double getTargetArea(){
            return getEntry("ta").getDouble(0.00);
        }

        /**
         * Set The LimeLight's Operation Mode
         * @param mode 0 = Vision Processor 1 = Driver Camera
         */
        public void setCamMode(int mode){
            getEntry("camMode").setNumber(mode);
        }

        /**
         * Sets The LimeLights Current Pipeline
         * @param pipeline Select Pipeline [0,9]
         */
        public void setPipeline(int pipeline){
            getEntry("pipeline").setNumber(pipeline);
        }

        /**
         * Set The LimeLights LED Mode:
         *  1 = Off
         *  2 = Blink
         *  3 = On
         * @param ledMode
         */
        public void setLED(int ledMode){
            getEntry("ledMode").setNumber(ledMode);
        }
    }
}
