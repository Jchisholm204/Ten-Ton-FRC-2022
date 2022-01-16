// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot;

import edu.wpi.first.networktables.LogMessage;
//import base
import edu.wpi.first.wpilibj.Joystick;
import edu.wpi.first.wpilibj.XboxController;
//import edu.wpi.first.wpilibj.
import edu.wpi.first.wpilibj.Timer;

import java.io.Console;
import java.util.concurrent.DelayQueue;

//import motor libraries - must be installed externally
import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.FeedbackDevice;
import com.ctre.phoenix.motorcontrol.NeutralMode;
import com.ctre.phoenix.motorcontrol.can.TalonFX;
import com.ctre.phoenix.motorcontrol.can.TalonSRX;

//imported by default
import edu.wpi.first.wpilibj.TimedRobot;
import edu.wpi.first.wpilibj.smartdashboard.SendableChooser;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import frc.robot.Controllers;

import frc.robot.modules.motorModules;

/**
 * The VM is configured to automatically run this class, and to call the functions corresponding to
 * each mode, as described in the TimedRobot documentation. If you change the name of this class or
 * the package after creating this project, you must also update the build.gradle file in the
 * project.
 */


public class Robot extends TimedRobot {
  private static final String kDefaultAuto = "No Auto";
  private String m_autoSelected;
  private final SendableChooser<String> m_auto_chooser = new SendableChooser<>();

  XboxController master = new XboxController(0);
  
  /**
   * This function is run when the robot is first started up and should be used for any
   * initialization code.
   */
  @Override
  public void robotInit() {
    //Auto Selector Code
    m_auto_chooser.setDefaultOption("Default Auto", kDefaultAuto);
    SmartDashboard.putData("Auto choices", m_auto_chooser);
  }

  /**
   * This function is called every robot packet, no matter the mode. Use this for items like
   * diagnostics that you want ran during disabled, autonomous, teleoperated and test.
   *
   * <p>This runs after the mode specific periodic functions, but before LiveWindow and
   * SmartDashboard integrated updating.
   */
  @Override
  public void robotPeriodic() {}

  /**
   * This autonomous (along with the chooser code above) shows how to select between different
   * autonomous modes using the dashboard. The sendable chooser code works with the Java
   * SmartDashboard. If you prefer the LabVIEW Dashboard, remove all of the chooser code and
   * uncomment the getString line to get the auto name from the text box below the Gyro
   *
   * <p>You can add additional auto modes by adding additional comparisons to the switch structure
   * below with additional strings. If using the SendableChooser make sure to add them to the
   * chooser code above as well.
   */
  @Override
  public void autonomousInit() {
    m_autoSelected = m_auto_chooser.getSelected();
    // m_autoSelected = SmartDashboard.getString("Auto Selector", kDefaultAuto);
    System.out.println("Auto selected: " + m_autoSelected);
  }

  /** This function is called periodically during autonomous. */
  @Override
  public void autonomousPeriodic() {
    switch (m_autoSelected) {
      case kDefaultAuto:
        break;
      default:
        // Put default auto code here
        break;
    }
  }

  /** This function is called once when teleop is enabled. */
  @Override
  public void teleopInit() {
    SmartDashboard.putNumber("FW Pow", 0);
    SmartDashboard.putNumber("Feeder One Pow", 0);
    SmartDashboard.putNumber("Feeder Two Pow", 0);
  }

  double testMotorPercentOut = 0;
  /** This function is called periodically during operator control. */
  @Override
  public void teleopPeriodic() {
    
    if(master.getYButtonPressed()){
      testMotorPercentOut = SmartDashboard.getNumber("Set Percent Pow", 0);
      testMotorPercentOut +=0.025;
      SmartDashboard.putNumber("Set Percent Pow", testMotorPercentOut);
    }
    else if(master.getAButtonPressed()){
      testMotorPercentOut = SmartDashboard.getNumber("Set Percent Pow", 0);
      testMotorPercentOut -=0.025;
      SmartDashboard.putNumber("Set Percent Pow", testMotorPercentOut);
    }
    else if(master.getXButtonPressed()){
      testMotorPercentOut = SmartDashboard.getNumber("Set Percent Pow", 0);
      testMotorPercentOut -=0.05;
      SmartDashboard.putNumber("Set Percent Pow", testMotorPercentOut);
    }
    else if(master.getBButtonPressed()){
      testMotorPercentOut = SmartDashboard.getNumber("Set Percent Pow", 0);
      testMotorPercentOut +=0.05;
      SmartDashboard.putNumber("Set Percent Pow", testMotorPercentOut);
    }
    if(master.getRightBumperPressed()){
      testMotorPercentOut = 0;
    }

    if(testMotorPercentOut > 100){
      testMotorPercentOut = 100;
    }
    if(testMotorPercentOut <-100){
      testMotorPercentOut = -100;
    }
    SmartDashboard.putNumber("Motor Output Percent", testMotor_Talon.getMotorOutputPercent()*100);
    SmartDashboard.putNumber("Motor Output Voltage", testMotor_Talon.getMotorOutputVoltage());
    SmartDashboard.putNumber("Motor RPM", motorModules.rtnVelocity(testMotor_Talon, 2048));
    SmartDashboard.putNumber("Motor Temp", testMotor_Talon.getTemperature());

    SmartDashboard.updateValues();

    double motorPercent = SmartDashboard.getNumber("Set Percent Pow", 0);

    double motorVal = Controllers.expo(motorPercent, 1.3, 0, 0);
  
    System.out.println("raw: " + motorPercent + "filtered: " + motorVal);

    testMotor_Talon.set(ControlMode.PercentOutput, (motorPercent/100));
  }

  /** This function is called once when the robot is disabled. */
  @Override
  public void disabledInit() {}

  /** This function is called periodically when disabled. */
  @Override
  public void disabledPeriodic() {}

  /** This function is called once when test mode is enabled. */
  @Override
  public void testInit() {}

  /** This function is called periodically during test mode. */
  @Override
  public void testPeriodic() {}
}
