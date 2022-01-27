package frc.robot.mapping;

import edu.wpi.first.wpilibj.XboxController;
import frc.robot.mapping.Constants;
import edu.wpi.first.wpilibj.DriverStation;

public class Controller {

    //Master Xbox Controller
    private static final XboxController master = new XboxController(Constants.RobotMap.Controller_Main.port);

    public Controller(){  }

    /**
     * Get The Master Controller
     * @return Xbox Controller Master
     */
    public static XboxController getMaster() {
        return master;
    }
}
