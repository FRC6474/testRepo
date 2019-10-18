/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/chassis.h"
#include "commands/tankDrive.h"
#include "frc/smartdashboard/SmartDashboard.h"

chassis::chassis() : Subsystem("ExampleSubsystem") {
  backLeft->SelectProfileSlot(0,0);
  backLeft->SetSensorPhase(true);
  backLeft->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute);
}

void chassis::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  SetDefaultCommand(new tankDrive());
}

void chassis::tank(double leftPower, double rightPower){
  frontLeft->Set(ControlMode::PercentOutput, -1*leftPower);
  frontRight->Set(ControlMode::PercentOutput, rightPower);
  backLeft->Set(ControlMode::PercentOutput, -1*leftPower);
  backRight->Set(ControlMode::PercentOutput, rightPower);
}

void chassis::driveRobot(double feet, double angle){
  encoderPosition = backLeft->GetSelectedSensorPosition();
  gyroPosition = gyro->GetAngle();

  frc::SmartDashboard::PutNumber("encoderpos", backLeft->GetOutputCurrent());
	frc::SmartDashboard::PutNumber("Forward pow", throttle);

  pos = feet;
  ang = angle;
  encoderError = encoderPosition - pos;
  gyroError = ang - gyroPosition;

  throttle = encoderP*encoderError;
  wheel = gyroP*gyroError;

  right = -throttle - wheel;
  left = -throttle + wheel;

  frontLeft->Set(ControlMode::PercentOutput, left);
  frontRight->Set(ControlMode::PercentOutput, -right);
  backLeft->Set(ControlMode::PercentOutput, left);
  backRight->Set(ControlMode::PercentOutput, -right);
}

void chassis::driveReset(){
  backLeft->SetSelectedSensorPosition(0);
}

void chassis::gyroReset(){
  gyro->Reset();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
