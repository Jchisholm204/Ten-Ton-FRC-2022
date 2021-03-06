#include "tools/Motors.hpp"

/**
 * Motor Configurations
 * @link Motors.hpp
 */

void motorConfiguration::Talon::intake(TalonSRX &iMotor, bool inverted){
    // Create the Motor Configuration
    TalonSRXConfiguration motorConfig;
    // Set the Primary Feedback Sensor (configure the motor's encoder)
    motorConfig.primaryPID.selectedFeedbackSensor = FeedbackDevice::None;
    // Configure the Motor's Integrated PID
    motorConfig.slot0.kP = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kI = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kD = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kF = 0.0505; // kF - Feed Forward Value - The Minimum Motor Power Required to Move the Motor

    motorConfig.slot0.integralZone = 0;
    motorConfig.slot0.allowableClosedloopError = 0;
    motorConfig.closedloopRamp = 0;

    motorConfig.motionAcceleration = 2000;
    motorConfig.motionCruiseVelocity = 22000; //Maximum Speed (encoder units / 100ms) for Magic Motion

    motorConfig.nominalOutputForward = 0.0;
    motorConfig.nominalOutputReverse = 0.0;
    motorConfig.peakOutputForward = 1.0;
    motorConfig.peakOutputReverse = -1.0;

    motorConfig.motionCurveStrength = 0;
    
    // Reset the Motor to Factory Settings before Applying Profile
    iMotor.ConfigFactoryDefault();
    // Apply our Motor Configuration Profile
    iMotor.ConfigAllSettings(motorConfig);
    //Set the Motor Inversion
    iMotor.SetInverted(inverted);
    //Set the Motors Neutral Mode (What it does when no power is being applied)
    iMotor.SetNeutralMode(NeutralMode::Coast);

}

void motorConfiguration::Talon::index(TalonSRX &iMotor, bool inverted){
    // Create the Motor Configuration
    TalonSRXConfiguration motorConfig;
    // Set the Primary Feedback Sensor (configure the motor's encoder)
    motorConfig.primaryPID.selectedFeedbackSensor = FeedbackDevice::None;
    // Configure the Motor's Integrated PID
    motorConfig.slot0.kP = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kI = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kD = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kF = 0.0505; // kF - Feed Forward Value - The Minimum Motor Power Required to Move the Motor

    motorConfig.slot0.integralZone = 0;
    motorConfig.slot0.allowableClosedloopError = 0;
    motorConfig.closedloopRamp = 0;

    motorConfig.motionAcceleration = 2000;
    motorConfig.motionCruiseVelocity = 22000; //Maximum Speed (encoder units / 100ms) for Magic Motion

    motorConfig.nominalOutputForward = 0.0;
    motorConfig.nominalOutputReverse = 0.0;
    motorConfig.peakOutputForward = 1.0;
    motorConfig.peakOutputReverse = -1.0;

    motorConfig.motionCurveStrength = 0;
    
    // Reset the Motor to Factory Settings before Applying Profile
    iMotor.ConfigFactoryDefault();
    // Apply our Motor Configuration Profile
    iMotor.ConfigAllSettings(motorConfig);
    //Set the Motor Inversion
    iMotor.SetInverted(inverted);
    //Set the Motors Neutral Mode (What it does when no power is being applied)
    iMotor.SetNeutralMode(NeutralMode::Brake);

}

void motorConfiguration::Talon::index(TalonFX &iMotor, bool inverted){
    // Create the Motor Configuration
    TalonFXConfiguration motorConfig;
    // Set the Primary Feedback Sensor (configure the motor's encoder)
    motorConfig.primaryPID.selectedFeedbackSensor = FeedbackDevice::IntegratedSensor;
    // Configure the Motor's Integrated PID
    motorConfig.slot0.kP = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kI = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kD = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kF = 0.0500; // kF - Feed Forward Value - The Minimum Motor Power Required to Move the Motor

    motorConfig.slot0.integralZone = 0;
    motorConfig.slot0.allowableClosedloopError = 0;
    motorConfig.closedloopRamp = 0.001;

    motorConfig.motionAcceleration = 20000;
    motorConfig.motionCruiseVelocity = 22000; //Maximum Speed (encoder units / 100ms) for Magic Motion

    motorConfig.nominalOutputForward = 0.0;
    motorConfig.nominalOutputReverse = 0.0;
    motorConfig.peakOutputForward = 1.0;
    motorConfig.peakOutputReverse = -1.0;

    motorConfig.motionCurveStrength = 0;
    
    // Reset the Motor to Factory Settings before Applying Profile
    iMotor.ConfigFactoryDefault();
    // Apply our Motor Configuration Profile
    iMotor.ConfigAllSettings(motorConfig);
    //Set the Motor Inversion
    iMotor.SetInverted(inverted);
    //Set the Motors Neutral Mode (What it does when no power is being applied)
    iMotor.SetNeutralMode(NeutralMode::Brake);

}

TalonFXConfiguration motorConfiguration::Talon::driveProfile(){

    // Create The Motor Configuration
    TalonFXConfiguration motorConfig;
    // Set the Primary Feedback Sensor (configure the motor's encoder)
    motorConfig.primaryPID.selectedFeedbackSensor = FeedbackDevice::IntegratedSensor;
    // Configure the Motor's Integrated PID
    motorConfig.slot0.kP = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kI = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kD = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kF = 0.050; // kF - Feed Forward Value - The Minimum Motor Power Required to Move the Motor

    motorConfig.slot0.integralZone = 0;
    motorConfig.slot0.allowableClosedloopError = 0;
    motorConfig.closedloopRamp = 0.48; //0.48

    motorConfig.motionAcceleration = 14000; //8000
    motorConfig.motionCruiseVelocity = 21000; //Maximum Speed (encoder units / 100ms) for Magic Motion

    motorConfig.nominalOutputForward = 0.0;
    motorConfig.nominalOutputReverse = 0.0;
    motorConfig.peakOutputForward = 1.0;
    motorConfig.peakOutputReverse = -1.0;

    motorConfig.motionCurveStrength = 3;

    return motorConfig;
}

void motorConfiguration::Talon::rightDrive(TalonFX &iMotor){
    
    // Reset the Motor to Factory Settings before Applying Profile
    iMotor.ConfigFactoryDefault();
    // Apply our Drive Motor Configuration Profile
    iMotor.ConfigAllSettings(driveProfile());
    //Set the Motor Inversion
    iMotor.SetInverted(true);
    //Set the Motors Neutral Mode (What it does when no power is being applied)
    iMotor.SetNeutralMode(NeutralMode::Brake);

}

void motorConfiguration::Talon::leftDrive(TalonFX &iMotor){

    // Reset the Motor to Factory Settings before Applying Profile
    iMotor.ConfigFactoryDefault();
    // Apply our Drive Motor Configuration Profile
    iMotor.ConfigAllSettings(driveProfile());
    //Set the Motor Inversion
    iMotor.SetInverted(false);
    //Set the Motors Neutral Mode (What it does when no power is being applied)
    iMotor.SetNeutralMode(NeutralMode::Brake);

}

void motorConfiguration::Talon::winchMotor(TalonFX &iMotor){
    // Create the Motor Configuration
    TalonFXConfiguration motorConfig;
    // Set the Primary Feedback Sensor (configure the motor's encoder)
    motorConfig.primaryPID.selectedFeedbackSensor = FeedbackDevice::IntegratedSensor;
    // Configure the Motor's Integrated PID
    motorConfig.slot0.kP = 1.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kI = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kD = 80.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kF = 0.0505; // kF - Feed Forward Value - The Minimum Motor Power Required to Move the Motor

    motorConfig.slot0.integralZone = 0;
    motorConfig.slot0.allowableClosedloopError = 0;
    motorConfig.closedloopRamp = 0.1;

    motorConfig.motionAcceleration = 15000;
    motorConfig.motionCruiseVelocity = 21000; //Maximum Speed (encoder units / 100ms) for Magic Motion

    motorConfig.nominalOutputForward = 0.0;
    motorConfig.nominalOutputReverse = 0.0;
    motorConfig.peakOutputForward = 1.0;
    motorConfig.peakOutputReverse = -1.0;

    motorConfig.motionCurveStrength = 0;
    
    // Reset the Motor to Factory Settings before Applying Profile
    iMotor.ConfigFactoryDefault();
    // Apply our Motor Configuration Profile
    iMotor.ConfigAllSettings(motorConfig);
    //Set the Motor Inversion
    iMotor.SetInverted(true);
    //Set the Motors Neutral Mode (What it does when no power is being applied)
    iMotor.SetNeutralMode(NeutralMode::Brake);

}

void motorConfiguration::Talon::clawMotor(TalonFX &iMotor){
    // Create the Motor Configuration
    TalonFXConfiguration motorConfig;
    // Set the Primary Feedback Sensor (configure the motor's encoder)
    motorConfig.primaryPID.selectedFeedbackSensor = FeedbackDevice::IntegratedSensor;
    // Configure the Motor's Integrated PID
    motorConfig.slot0.kP = 2.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kI = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kD = 80.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kF = 0.0505; // kF - Feed Forward Value - The Minimum Motor Power Required to Move the Motor

    motorConfig.slot0.integralZone = 0;
    motorConfig.slot0.allowableClosedloopError = 0;
    motorConfig.closedloopRamp = 0.1;

    motorConfig.motionAcceleration = 15000;
    motorConfig.motionCruiseVelocity = 21000; //Maximum Speed (encoder units / 100ms) for Magic Motion

    motorConfig.nominalOutputForward = 0.0;
    motorConfig.nominalOutputReverse = 0.0;
    motorConfig.peakOutputForward = 1.0;
    motorConfig.peakOutputReverse = -1.0;

    motorConfig.motionCurveStrength = 0;
    
    // Reset the Motor to Factory Settings before Applying Profile
    iMotor.ConfigFactoryDefault();
    // Apply our Motor Configuration Profile
    iMotor.ConfigAllSettings(motorConfig);
    //Set the Motor Inversion
    iMotor.SetInverted(true);
    //Set the Motors Neutral Mode (What it does when no power is being applied)
    iMotor.SetNeutralMode(NeutralMode::Brake);

}