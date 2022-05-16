// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/TrackingSubsystem.hpp"
#include <frc/RobotController.h>

TrackingSubsystem::TrackingSubsystem() {
  // Implementation of subsystem constructor goes here.
}

double TrackingSubsystem::getX(){
  return FieldDistance[X];
}

double TrackingSubsystem::getY(){
  return FieldDistance[Y];
}

double TrackingSubsystem::getHeading(){
  return (navX0.GetYaw() + navX1.GetYaw())/2;
}

double TrackingSubsystem::get(Direction direction, DataType type){
  switch (type)
  {
  case Accel:
    return FieldAcceleration[direction];
    break;
  case Vel:
    return FieldVelocity[direction];
    break;
  case Dist:
    return FieldDistance[direction];
    break;
  default:
    break;
  }
}

void TrackingSubsystem::Periodic() {
  // Compute the Heading of the robot based on the average heading of the NavX Sensors
  headingAvg = getHeading();

  // Compute the Time Difference since the last interval
  loopIDCX = frc::RobotController::GetFPGATime() * 1.0e-3 - loopIDCL;
  loopIDCL = frc::RobotController::GetFPGATime() * 1.0e-3;

  // Derrive and Scale the Robot X vector to the Real world X and Y Vectors
  double robotAccelX = (navX0.GetWorldLinearAccelX() + navX1.GetWorldLinearAccelX())/2;
  FieldAcceleration[X] = cos(headingAvg*M_PIl/180)*robotAccelX;
  FieldAcceleration[Y] = sin(headingAvg*M_PIl/180)*robotAccelX;

  // Derrive and Scale the Robot Y vector to the Real world X and Y Vectors
  double robotAccelY = (navX0.GetWorldLinearAccelY() + navX1.GetWorldLinearAccelY())/2;
  FieldAcceleration[Y] = cos(headingAvg*M_PIl/180)*robotAccelY;
  FieldAcceleration[X] = sin(headingAvg*M_PIl/180)*robotAccelY;

  FieldVelocity[X] += FieldAcceleration[X]*(loopIDCX);
  FieldVelocity[Y] += FieldAcceleration[Y]*(loopIDCX);

  FieldDistance[X] += FieldVelocity[X]*(loopIDCX);
  FieldDistance[Y] += FieldVelocity[Y]*(loopIDCX);
}