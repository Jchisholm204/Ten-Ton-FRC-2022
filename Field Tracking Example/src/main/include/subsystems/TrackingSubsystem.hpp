// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <AHRS.h>
#include <frc/SPI.h>

class TrackingSubsystem : public frc2::SubsystemBase {
 public:

  //Directions
  enum Direction{
    X, Y
  };

  // Datatypes
  enum DataType{
    Accel, Vel, Dist
  };
  
  TrackingSubsystem();

  double getX();

  double getY();

  double getHeading();

  double get(Direction direction, DataType type);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  AHRS navX0{frc::SPI::kOnboardCS0};
  AHRS navX1{frc::SPI::kOnboardCS1};
  //AHRS navX2{frc::SPI::kOnboardCS2};
  //AHRS navX3{frc::SPI::kOnboardCS3};

  double FieldAcceleration[2];
  double FieldVelocity[2];
  double FieldDistance[2];
  double headingAvg;

  double loopIDCL;
  double loopIDCX;

};
