#include "utilities/Talon.hpp"

void TalonConfiguation::intake(TalonSRX &iMotor, bool inverted){
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

void TalonConfiguation::index(TalonSRX &iMotor, bool inverted){
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

void TalonConfiguation::rightDrive(TalonFX &iMotor){
    // Create the Motor Configuration
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
    motorConfig.closedloopRamp = 1;

    motorConfig.motionAcceleration = 2000;
    motorConfig.motionCruiseVelocity = 21000; //Maximum Speed (encoder units / 100ms) for Magic Motion

    motorConfig.nominalOutputForward = 0.0;
    motorConfig.nominalOutputReverse = 0.0;
    motorConfig.peakOutputForward = 1.0;
    motorConfig.peakOutputReverse = -1.0;

    motorConfig.motionCurveStrength = 4;
    
    // Reset the Motor to Factory Settings before Applying Profile
    iMotor.ConfigFactoryDefault();
    // Apply our Motor Configuration Profile
    iMotor.ConfigAllSettings(motorConfig);
    //Set the Motor Inversion
    iMotor.SetInverted(false);
    //Set the Motors Neutral Mode (What it does when no power is being applied)
    iMotor.SetNeutralMode(NeutralMode::Brake);

}

void TalonConfiguation::leftDrive(TalonFX &iMotor){
    // Create the Motor Configuration
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
    motorConfig.closedloopRamp = 1;

    motorConfig.motionAcceleration = 2000;
    motorConfig.motionCruiseVelocity = 21000; //Maximum Speed (encoder units / 100ms) for Magic Motion

    motorConfig.nominalOutputForward = 0.0;
    motorConfig.nominalOutputReverse = 0.0;
    motorConfig.peakOutputForward = 1.0;
    motorConfig.peakOutputReverse = -1.0;

    motorConfig.motionCurveStrength = 4;
    
    // Reset the Motor to Factory Settings before Applying Profile
    iMotor.ConfigFactoryDefault();
    // Apply our Motor Configuration Profile
    iMotor.ConfigAllSettings(motorConfig);
    //Set the Motor Inversion
    iMotor.SetInverted(true);
    //Set the Motors Neutral Mode (What it does when no power is being applied)
    iMotor.SetNeutralMode(NeutralMode::Brake);

}

void TalonConfiguation::winchMotor(TalonFX &iMotor){
    // Create the Motor Configuration
    TalonFXConfiguration motorConfig;
    // Set the Primary Feedback Sensor (configure the motor's encoder)
    motorConfig.primaryPID.selectedFeedbackSensor = FeedbackDevice::IntegratedSensor;
    // Configure the Motor's Integrated PID
    motorConfig.slot0.kP = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kI = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kD = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kF = 0.0505; // kF - Feed Forward Value - The Minimum Motor Power Required to Move the Motor

    motorConfig.slot0.integralZone = 0;
    motorConfig.slot0.allowableClosedloopError = 0;
    motorConfig.closedloopRamp = 2;

    motorConfig.motionAcceleration = 1000;
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
    iMotor.SetInverted(true);
    //Set the Motors Neutral Mode (What it does when no power is being applied)
    iMotor.SetNeutralMode(NeutralMode::Brake);

}

void TalonConfiguation::clawMotor(TalonFX &iMotor){
    // Create the Motor Configuration
    TalonFXConfiguration motorConfig;
    // Set the Primary Feedback Sensor (configure the motor's encoder)
    motorConfig.primaryPID.selectedFeedbackSensor = FeedbackDevice::IntegratedSensor;
    // Configure the Motor's Integrated PID
    motorConfig.slot0.kP = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kI = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kD = 0.0; // Standard PID kP - used for MagicMotion Movement
    motorConfig.slot0.kF = 0.0505; // kF - Feed Forward Value - The Minimum Motor Power Required to Move the Motor

    motorConfig.slot0.integralZone = 0;
    motorConfig.slot0.allowableClosedloopError = 0;
    motorConfig.closedloopRamp = 0.5;

    motorConfig.motionAcceleration = 1500;
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