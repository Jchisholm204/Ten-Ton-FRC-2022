package frc.robot.utilities;

public class Exponential {
    /**
     * 
     * @param joyVal Input Joystick Value
     * @param exPower Power for the Expo Function (1, 2)
     * @param joyDead Controller Deadzone
     * @param motorMin Minimum motor output to start moving
     * @return Motor Output With an Exponential Curve
     */
    public static double exponential(final double joyVal, final double exPower, final double joyDead, final double motorMin){
        double joySign;
        final double joyMax = 1-joyDead;
        final double joyLive = Math.abs(joyVal) - joyDead;
        if(joyVal > 0) { joySign = 1; }
        else if(joyVal < 0) { joySign = -1; }
        else { joySign = 0; };
        double power = (joySign * (motorMin + ((1 - motorMin) * (Math.pow(joyLive, exPower) / Math.pow(joyMax, exPower)))));
        return power;
    }
}
