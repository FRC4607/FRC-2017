// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutonomousCommand.h"

int count=0;
/*AutoForward::AutoForward(float speed) {
	Requires(Robot::drivetrain);
		this->speed = speed;
		time= 5;
}*/
AutoForward::AutoForward(float speed, float time) {
	Requires(Robot::drivetrain.get());
		this->speed = speed;
		this->time = time;

		SmartDashboard::PutString("AutoForward: speed: ",std::to_string(speed));
		SmartDashboard::PutString("AutoForward: time: ",std::to_string(time));
}

// Called just before this Command runs the first time
void AutoForward::Initialize() {
	SetTimeout(this->time);
	//frc::Command::SetTimeout(.5);
	SmartDashboard::PutString("AutoForward: Initialize: time: ",std::to_string(time));
}

// Called repeatedly when this Command is scheduled to run
void AutoForward::Execute() {
	RobotMap::drivetrainFrontLeft->Set(this->speed);
	RobotMap::drivetrainRearLeft->Set(this->speed);
	RobotMap::drivetrainFrontRight->Set(-this->speed);
	RobotMap::drivetrainRearRight->Set(-this->speed);
	SmartDashboard::PutString("AutoForward: Execute count: ",std::to_string(++count));

}

// Make this return true when this Command no longer needs to run execute()
bool AutoForward::IsFinished() {
	SmartDashboard::PutString("AutoForward: IsFinished: IsTimedOut: ", std::to_string(IsTimedOut()));
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoForward::End() {
	RobotMap::drivetrainFrontLeft->Set(0);
	RobotMap::drivetrainRearLeft->Set(0);
	RobotMap::drivetrainFrontRight->Set(0);
	RobotMap::drivetrainRearRight->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoForward::Interrupted() {

}
