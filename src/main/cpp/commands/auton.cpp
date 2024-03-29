/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/auton.h"

auton::auton() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_chassis);
}

// Called just before this Command runs the first time
void auton::Initialize() {
  Robot::m_chassis.driveReset();
  Robot::m_chassis.gyroReset();
}

// Called repeatedly when this Command is scheduled to run
void auton::Execute() {
 // Robot::m_chassis.driveRobot(2, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool auton::IsFinished() { return false; }

// Called once after isFinished returns true
void auton::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void auton::Interrupted() {}
