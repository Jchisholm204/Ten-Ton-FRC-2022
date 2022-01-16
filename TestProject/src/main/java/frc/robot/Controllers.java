package frc.robot;
import java.lang.Math;

public class Controllers {
    public static double expo(double iip, double d, int deadZone, int motorMin){
        double joySign;
        double joyMax = 101 - deadZone;
        double joyLive = Math.abs(iip) - deadZone;
        if(iip > 0){joySign = 1;}
        else if(iip < 0){joySign = -1;}
        else{joySign = 0;}
        double power = joySign * (motorMin + ((100 - motorMin) * (Math.pow(joyLive, d) / Math.pow(joyMax, d))));
        return power;
      }
    
    public static double getVel(double input, double kMaxRPM, double kSensorUnitsPerRotation, double kGearRatio){
      double velocityPeak = (kMaxRPM / 600) * (kSensorUnitsPerRotation / kGearRatio);
      double velocity = (input/velocityPeak) * kMaxRPM;
      return velocityPeak;
    }
}
