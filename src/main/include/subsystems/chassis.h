/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/Phoenix.h>
#include <frc/commands/Subsystem.h>
#include <frc/AnalogGyro.h>

class chassis : public frc::Subsystem {
 private:
 TalonSRX *frontLeft = new TalonSRX(7);
 TalonSRX *frontRight = new TalonSRX(4);
 TalonSRX *backLeft = new TalonSRX(10);
 TalonSRX *backRight = new TalonSRX(8);

 frc::AnalogGyro *gyro = new frc::AnalogGyro(0);

 //Variables
 double encoderPosition;
 double gyroPosition;
 double encoderError;
 double gyroError;
 double currentEncoder;
 double currentGyro;
 double throttle;
 double wheel;
 double encoderP = 0.3;
 double gyroP = 0.075;
 double pos;
 double ang; 
 double left;
 double right;
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  chassis();
  void InitDefaultCommand() override;
  void tank(double left, double right);
  void driveRobot(double feet, double angle);
  void driveReset();
  void gyroReset();
};
