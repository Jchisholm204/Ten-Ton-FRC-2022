package frc.robot;

//Import Controller Libs
import edu.wpi.first.wpilibj.XboxController;

public class IO {
    //Creates Master Drive Controller
    public final XboxController master = new XboxController(Constants.RobotMap.Controller_Main.port);
    //Creates Partner Drive Controller
    //public final XboxController partner = new XboxController(Constants.RobotMap.Controller_Partner.port);

    public IO(){}
}
