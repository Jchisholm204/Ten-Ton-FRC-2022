package frc.robot.utilities;

public class PID {

    private float kP;
    private float kD;
    public double current;
    public double target;
    private double error;
    private double error_last;
    private double derr;

    public PID(float p, float d, int targ){
        kP = p;
        kD = d;

        target = targ;
        current = 0;

        error = 0;
        error_last = 0;
    }

    public void set_vars(float p, float d, int targ){
        kP = p;
        kD = d;

        target = targ;
    }

    public double output(double maxPower){
        double output;

        error = target - current;

        derr = error - error_last;

        error_last = error;

        output = (error * kP) + (derr * kD);

        if(Math.abs(output) > maxPower){
            output = maxPower * output/Math.abs(output);
        }

        return output;

    }
    
}
