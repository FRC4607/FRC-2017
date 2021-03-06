// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "../RobotMap.h"
#include "../Commands/Driving.h"
#include "Drivetrain.h"

#include <cmath>
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Drivetrain::Drivetrain() : PIDSubsystem("Drivetrain" , .09,0,.0025) {
	SetOutputRange(-.5, .5);
	//SetAbsoluteTolerance(2);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    frontLeft = RobotMap::drivetrainFrontLeft;
    frontRight = RobotMap::drivetrainFrontRight;
    rearLeft = RobotMap::drivetrainRearLeft;
    rearRight = RobotMap::drivetrainRearRight;
    frontStrafe = RobotMap::drivetrainFrontStrafe;
    rearStrafe = RobotMap::drivetrainRearStrafe;
    ahrs = RobotMap::drivetrainAHRS;
    encoderRearLeft = RobotMap::drivetrainEncoderRearLeft;
    encoderRearRight = RobotMap::drivetrainEncoderRearLeft;
    encoderRightStrafe = RobotMap::drivetrainEncoderRightStrafe;
    fieldOrient = false;
    pIDControllerDrivetrain = RobotMap::drivetrainLeftPIDController;
    leftSpeed=0;
    rightSpeed=0;
    frontStrafeSpeed=0;
    rearStrafeSpeed=0;
    y = 0;
    x=0;

    // these are where the inputs of x and y come into play. They are currently set to 1 just because I don't have the input yet.

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}


void Drivetrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
     SetDefaultCommand(new Driving());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Drivetrain::DrivingWithJoystick() {
	std::shared_ptr<Joystick> joy = Robot::oi->getDriver();
	float x,y, z;
	float const PI= 3.14159;
	float adjustmentAngle = PI/2;
	std::shared_ptr<Joystick> Pilot=joy;

	if (fieldOrient==true) {

		adjustmentAngle = ahrs->GetAngle()*PI/180+PI/2;

	}
	x=Pilot->GetMagnitude()*cos(Pilot->GetDirectionRadians()-adjustmentAngle);
	y=Pilot->GetMagnitude()*sin(Pilot->GetDirectionRadians()-adjustmentAngle);
	z = joy->GetZ();


	if( Robot::oi->driverIsXbox){
		z = joy->GetX(Joystick::kRightHand);
	}

	if(targetLock){
		//Inverting because it will be inverted again next,
		//Could be wrong though
		z = -1*leftSpeedAdjustment;
	}

	leftSpeed = y- z;
	rightSpeed = y*-1 - z;

	frontStrafeSpeed = x*-2;
	rearStrafeSpeed = x*2;
	// Strafing isn't working properly.  Needs fix around this area maybe?

	NormalizeInputs(leftSpeed, rightSpeed, frontStrafeSpeed, rearStrafeSpeed);


	if (fabs(rearStrafeSpeed) > .25 || fieldOrient) {
		//RobotMap::pneumaticsFrontStrafe->Set(DoubleSolenoid::Value::kForward);
		RobotMap::pneumaticsRearStrafe->Set(DoubleSolenoid::Value::kForward);

	}

	else {
		//RobotMap::pneumaticsFrontStrafe->Set(DoubleSolenoid::Value::kReverse);
		RobotMap::pneumaticsRearStrafe->Set(DoubleSolenoid::Value::kReverse);
	}

	if (fabs(leftSpeed) < .09) {
		leftSpeed=0;

	}
	if (fabs(rightSpeed) < .09) {
		rightSpeed=0;

	}

	SmoothMotion(frontLeft->Get(), leftSpeed, .07);
	SmoothMotion(frontRight->Get(), rightSpeed, .07);
	SmoothMotion(frontStrafe->Get(), frontStrafeSpeed, .07);
	SmoothMotion(rearStrafe->Get(), rearStrafeSpeed, .07);
	frontLeft->Set(leftSpeed);
	rearLeft->Set(leftSpeed);
	frontRight->Set(rightSpeed);
	rearRight->Set(rightSpeed);
	frontStrafe->Set(frontStrafeSpeed);
	rearStrafe->Set(rearStrafeSpeed);

	SmartDashboard::PutNumber("Front Left Speed", frontLeft->Get());
	SmartDashboard::PutBoolean("Field Orient", fieldOrient);

}

void Drivetrain::DrivingWithVision(float x, float y) {
	float const PI= 3.14159;
	float adjustmentAngle = PI/2;

	if (fieldOrient==true) {

		adjustmentAngle = ahrs->GetAngle()*PI/180+PI/2;

	}

	leftSpeed = -y;
	rightSpeed = y;

	frontStrafeSpeed = x*-2;
	rearStrafeSpeed = x*2;
	// Strafing isn't working properly.  Needs fix around this area maybe?

	NormalizeInputs(leftSpeed, rightSpeed, frontStrafeSpeed, rearStrafeSpeed);


	if (fabs(rearStrafeSpeed) > .25 || fieldOrient) {
		//RobotMap::pneumaticsFrontStrafe->Set(DoubleSolenoid::Value::kForward);
		RobotMap::pneumaticsRearStrafe->Set(DoubleSolenoid::Value::kForward);

	}

	else {
		//RobotMap::pneumaticsFrontStrafe->Set(DoubleSolenoid::Value::kReverse);
		RobotMap::pneumaticsRearStrafe->Set(DoubleSolenoid::Value::kReverse);
	}

	if (fabs(leftSpeed) < .09) {
		leftSpeed=0;

	}
	if (fabs(rightSpeed) < .09) {
		rightSpeed=0;

	}

	SmoothMotion(frontLeft->Get(), leftSpeed, .07);
	SmoothMotion(frontRight->Get(), rightSpeed, .07);
	SmoothMotion(frontStrafe->Get(), frontStrafeSpeed, .07);
	SmoothMotion(rearStrafe->Get(), rearStrafeSpeed, .07);
	frontLeft->Set(leftSpeed);
	rearLeft->Set(leftSpeed);
	frontRight->Set(rightSpeed);
	rearRight->Set(rightSpeed);
	frontStrafe->Set(frontStrafeSpeed);
	rearStrafe->Set(rearStrafeSpeed);

	SmartDashboard::PutNumber("Front Left Speed", frontLeft->Get());
	SmartDashboard::PutBoolean("Field Orient", fieldOrient);

}

double Drivetrain::ReturnPIDInput() {

	return ahrs->GetAngle();

}

void Drivetrain::UsePIDOutput(double output) {
	if( drivetrainPIDRunning){
		leftSpeedAdjustment = -output;
		rightSpeedAdjustment = -output;
	}
	else{
		frontRight->Set(-output);
		frontLeft->Set(-output);
		rearLeft->Set(-output);
		rearRight->Set(-output);
	}
}

void Drivetrain::SetTargetLock(bool t){
	targetLock = t;
}
bool Drivetrain::GetTargetLock(){
	return targetLock;
}


void Drivetrain::SetFieldOrient(bool value){
	fieldOrient = value;

}

bool Drivetrain::GetFieldOrient(){
	return fieldOrient;
}
double *Drivetrain::FieldOriented(double x, double y, double z){
	//double adjustmentAngle;
	//float const PI= 3.14159;

	if (fieldOrient==true) {

		//	adjustmentAngle = ahrs->GetAngle()*PI/180+PI/2;

		}
		//x=Pilot->GetMagnitude()*cos(Pilot->GetDirectionRadians()-adjustmentAngle);
		//y=Pilot->GetMagnitude()*sin(Pilot->GetDirectionRadians()-adjustmentAngle);

		leftSpeed = y- z;
		rightSpeed = y*-1 - z;

		frontStrafeSpeed = x*-2;
		rearStrafeSpeed = x*2;
		speeds[0] = leftSpeed;
		speeds[1] = rightSpeed;
		speeds[2] = frontStrafeSpeed;
		speeds[3] = rearStrafeSpeed;
		return speeds;
}

void Drivetrain::AllignWithGearPeg() {

	//Vertical field of view of the zed,
	  // base on formula from http://www.rjdown.co.uk/projects/bfbc2/fovcalculator.php
	  const float PIXYCAM_HEIGHT_FT =  1.75; //The height of the center of the lens of the zed mounted on the robot in ft

	  double zedValue, x, y, z, b, xdc, ydc;
	  const float PI = 3.14159;
	  double width = 640;
	  double height = 400;

	  double VFOV = 47;
	  double HFOV = 75;
	  double x2;
	  double y2;

	  if(!Robot::vision->empty){
	  //These are going to be set to values from the pixy later on. Set to 1 for the time being, not an actual value.

	  x = 1;
	  y = 1;


	  //Convert pixel and zed values to X,Y,Z offsets in  feet


		  xdc = x - width / 2; //Pixels from the center the object center is in the x direction
		  ydc = height / 2 - y;//Pixels from the center the object center is in the y direction

		z = 13.25; //z is height of the center of the tape target in inches
		zedValue = (z - PIXYCAM_HEIGHT_FT * 12) / sin(ydc*VFOV / height);

	    //b is the diagonal from the zed to the observed point at the same height as the camera
	    b = sqrt(pow(zedValue,2)-pow(z,2)); //Pythagorean Theorem

	    xdc = x - width / 2; //Pixels from the center the object center is in the x direction
	    ydc = height / 2 - y; //Pixels from the center the object center is in the y direction

	    x = b*sin((xdc*HFOV/width) * PI/180); //Law of Sines
	    y = b*sin((90-xdc*HFOV/width) * PI/180); //Law of Sines

	    zedValue = (z - PIXYCAM_HEIGHT_FT * 12) / sin(ydc*VFOV / height);

	    //b is the diagonal from the zed to the observed point at the same height as the camera
	    b = sqrt(pow(zedValue,2)-pow(z,2)); //Pythagorean Theorem

	    x2= b*sin((xdc*HFOV/width) * PI/180); //Law of Sines
	    y2= b*sin((90-xdc*HFOV/width) * PI/180); //Law of Sines
	    springX = (x2 + x) / 2;
	    springY = (y2 + y) / 2;
	  }
}


float Drivetrain::SmoothMotion(float motorSpeed, float speed, float accelLim){

		float outputSpeed, accelSign, accel;
		accel = speed-motorSpeed;
		accelSign = fabs(speed-motorSpeed)/(speed-motorSpeed);

		if(fabs(accel)- accelLim > 0){
			outputSpeed = motorSpeed+accelLim*accelSign;
		}
		else{
			outputSpeed = speed;
		}
		return outputSpeed;
	}

void Drivetrain::NormalizeInputs(float& leftSpeed,float& rightSpeed,float& frontStrafeSpeed,float& rearStrafeSpeed){
	float maxSpeed;
	float signLS, signRS, signFSS, signRSS;
	signLS = leftSpeed/fabs(leftSpeed);
	signRS = rightSpeed/fabs(rightSpeed);
	signFSS = frontStrafeSpeed/fabs(frontStrafeSpeed);
	signRSS = rearStrafeSpeed/fabs(rearStrafeSpeed);

	if(fabs(leftSpeed) > 1 || fabs(rightSpeed) > 1 || fabs(frontStrafeSpeed) > 1 || fabs(rearStrafeSpeed) > 1){

		if(leftSpeed > rightSpeed && leftSpeed > frontStrafeSpeed && leftSpeed > rearStrafeSpeed){
			maxSpeed = leftSpeed;
		}
		else if(rightSpeed > frontStrafeSpeed && rightSpeed > rearStrafeSpeed){
			maxSpeed = rightSpeed;
		}
		else if(frontStrafeSpeed > rearStrafeSpeed){
			maxSpeed = frontStrafeSpeed;
		}
		else {
			maxSpeed = rearStrafeSpeed;
		}

		leftSpeed = fabs(leftSpeed/maxSpeed)*signLS;
		rightSpeed = fabs(rightSpeed/maxSpeed)*signRS;
		frontStrafeSpeed = fabs(frontStrafeSpeed/maxSpeed)*signFSS;
		rearStrafeSpeed = fabs(rearStrafeSpeed/maxSpeed)*signRSS;
	}
}

