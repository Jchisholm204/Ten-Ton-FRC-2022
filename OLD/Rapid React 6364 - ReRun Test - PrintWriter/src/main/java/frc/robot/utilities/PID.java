package frc.robot.utilities;

public class PID {

    private float kP;
    private float kD;
    public int current;
    public int target;
    private int error;
    private int error_last;
    private int derr;

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
