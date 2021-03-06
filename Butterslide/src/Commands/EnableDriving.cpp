#include "EnableDriving.h"

EnableDriving::EnableDriving() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void EnableDriving::Initialize() {

	//Turn off target lock
	Robot::drivetrain->SetTargetLock(false);

	Robot::drivetrain->Disable();
}

// Called repeatedly when this Command is scheduled to run
void EnableDriving::Execute() {
	Robot::drivetrain->DrivingWithJoystick();
}

// Make this return true when this Command no longer needs to run execute()
bool EnableDriving::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void EnableDriving::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EnableDriving::Interrupted() {
	End();
}
