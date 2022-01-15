package frc.robot;
import java.lang.Math;

public class Controllers {
    public static double expo(float iip, double d, int deadZone, int motorMin){
        double joySign;
        double joyMax = 128 - deadZone;
        double joyLive = Math.abs(iip) - deadZone;
        if(iip > 0){joySign = 1;}
        else if(iip < 0){joySign = -1;}
        else{joySign = 0;}
        double power = joySign * (motorMin + ((127 - motorMin) * (Math.pow(joyLive, d) / Math.pow(joyMax, d))));
        return power;
      }
}
