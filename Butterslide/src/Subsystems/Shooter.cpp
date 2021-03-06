#include "Shooter.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../Commands/ShootSetPoint.h"

Shooter::Shooter() : Subsystem("Shooter") {
	gun = RobotMap::rpg1;
	gun->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	gun->SetSensorDirection(true);
	gun->SetAllowableClosedLoopErr(0);
	gun->SelectProfileSlot(0);
	gun->SetF(m_f);
	gun->SetP(m_p);
	gun->SetI(m_i);
	gun->SetD(m_d);
	gun->SetVoltageRampRate(m_rampRate);
	gun->SetIzone(m_iz);
	SmartDashboard::PutNumber("Shooter RPM: ", m_rpm);
	SmartDashboard::PutNumber("Shooter P: ", m_p);
	SmartDashboard::PutNumber("Shooter I: ", m_i);
	SmartDashboard::PutNumber("Shooter D: ", m_d);
	SmartDashboard::PutNumber("Shooter F: ", m_f);
	SmartDashboard::PutNumber("Shooter Ramp Rate: ", m_rampRate);
	SmartDashboard::PutNumber("Shooter I Zone: ", m_iz);
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	// SetDefaultCommand(new ShootSetPoint(-500));
}

void Shooter::ImaFireInMaleeba(float speed){
	gun->Set(speed);
}
double Shooter::CalculateShooterSpeedFPS(double distanceFromBoilerY){
	const double shooterHeight = 1.75, g = 32.17, hoodAngle = 75*3.14159/180, boilerHeight = 8, boilerRadius = (21/2)/12;
	double x = distanceFromBoilerY/12 + boilerRadius, shooterSpeed;


	//Non-obvious calculation of shooterSpeed given distance from boiler
	shooterSpeed = x * sqrt( g / ( 2 * tan(hoodAngle) * x - (boilerHeight - shooterHeight) ) ) / cos(hoodAngle);

	/*
	 * The above calculation is derived from the following equations:
	 * xVel = cos(theta)*shooterSpeed
	 * yVel = sin(theta)*shooterSpeed
	 * x = xInitial + xVel * t
	 * y = yInitial + yVel * t - 1/2 * g * t^2
	 *
	 * xInitial is determined to be 0, since there is no offset from the distance to the boiler being 0
	 * because the distance to the boilerRadius is included in x
	 * yInitial is determined to be the shooterHeight since the balls exit the shooter at the height of the shooter
	 */

	return shooterSpeed;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
