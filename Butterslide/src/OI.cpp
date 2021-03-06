// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/ChangeMode.h"
#include "Commands/Feed.h"
#include "Commands/Suck.h"
#include "Commands/Shooting.h"
#include "Commands/UnSuck.h"
#include "Commands/RotateToAngle.h"
#include "Commands/EnableDriving.h"
#include "Commands/DrivetrainPID.h"
#include "Commands/Climbing.h"
#include "Commands/Driving.h"
#include "Commands/ShootSetPoint.h"
#include "Commands/PunchOut.h"
#include "Commands/PunchIn.h"
#include "Commands/AllignWithPeg.h"
#include "Commands/GearIntake.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driver.reset(new Joystick(0));
    captain.reset(new Joystick(1));
    
    int tractionModeBtn = 3,
    	fieldOrientBtn = 7,
		gyroResetBtn = 11,
		fireAwayBtn = 1,
		suckItUpBtn = 2,
		getItOutBtn = 9,
		loadItUpBtn = 4,
		rotateToAngleBtn = 10,
		enableDrivingBtn = 12;


    if(driver->GetType() == GenericHID::HIDType::kHIDGamepad || driver->GetType() == GenericHID::HIDType::kXInputGamepad || driver->GetType() == GenericHID::HIDType::kXInputArcadePad){
    	tractionModeBtn = 1, //A
 	   	fieldOrientBtn = 4,  //Y
    	gyroResetBtn = 2, //B
    	rotateToAngleBtn = 7, //Back
    	enableDrivingBtn = 9; //Pushing in/clicking left stick
    	driverIsXbox = true;
    	if(captain == driver){
    		fireAwayBtn = 6, //RB
    		suckItUpBtn = 5, //LB
    		getItOutBtn = 8, //Start
    		loadItUpBtn = 3; //X
    	}
    }

// traction mode is not enabled anymore because we don't have air being used on our bot anymore to use it

   // tractionMode.reset(new JoystickButton(driver.get(), tractionModeBtn));
   // tractionMode->WhenPressed(new ChangeMode(7));

   // fieldOrient.reset(new JoystickButton(driver.get(), fieldOrientBtn));
   // fieldOrient->WhenPressed(new ChangeMode(9));

    //gyroReset.reset(new JoystickButton(driver.get(), gyroResetBtn));
    //gyroReset->WhenPressed(new ChangeMode(8));
//ayyyyyyyyyyyyyyyyyyyyyyyyyyyy
 //   fireAway.reset(new JoystickButton(captain.get(), fireAwayBtn));
  //  fireAway->WhenPressed(new Shooting());

  //  suckItUp.reset(new JoystickButton(captain.get(), suckItUpBtn));
 //   suckItUp->WhenPressed(new Suck());

  // getItOut.reset(new JoystickButton(captain.get(), getItOutBtn));
  //  getItOut->WhenPressed(new UnSuck());

  //  loadItUp.reset(new JoystickButton(captain.get(), loadItUpBtn));
 //   loadItUp->WhenPressed(new Feed(-.85));
    //ayyyyyyyyyyyyyyyyyyyyyyyyyyyy

   //rotateToAngle.reset(new JoystickButton(driver.get(), 4));
   //rotateToAngle->WhenPressed(new RotateToAngle(420));

 //  rotateToTarget.reset(new JoystickButton(driver.get(), 4));
//   rotateToTarget->WhenPressed(new RotateToAngle(0, true));

 //  enableDriving.reset(new JoystickButton(driver.get(), enableDrivingBtn));
 //  enableDriving->WhenPressed(new Driving());

  //  strafePID.reset(new JoystickButton(driver.get(), 5));
   // strafePID->WhenPressed(new DrivetrainPID(0,0,36,false,false,0));

    //forwardPID.reset(new JoystickButton(driver.get(), 3));
    //forwardPID->WhenPressed( new DrivetrainPID(25,-25,0, false, false, 0));
//ayyyyyyyyyyyyyyyyyyyyyyyyyyyyy
    liftOff.reset(new JoystickButton(captain.get(), 6));
    liftOff->WhenPressed(new Climbing());
//ayyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy

  //  shootSetPointBB.reset(new JoystickButton(captain.get(), 5));
 //   shootSetPointBB->WhenPressed(new ShootSetPoint(-1900));
    // Stops with button 3 on captain (in shootsetpointBB line 31)

  //  punchOut.reset(new JoystickButton(driver.get(), 1));
  //  punchOut->WhenPressed(new PunchOut());

 //   punchIn.reset(new JoystickButton(driver.get(), 2));
  //  punchIn->WhenPressed(new PunchIn());

    //activateVision.reset(new JoystickButton(captain.get(), 10));
   // activateVision->WhenPressed(new AllignWithPeg(1));


// Gearage Buttons
    GearIn.reset(new JoystickButton(captain.get(), 1));
    GearIn->WhenPressed(new GearIntake());


    // SmartDashboard Buttons
    SmartDashboard::PutData("Traction Mode", new ChangeMode(7));
    SmartDashboard::PutData("Align with Gear Peg- CENTER", new AllignWithPeg(AllignWithPeg::CENTER));
    SmartDashboard::PutData("Align with Gear Peg- DRIVE FORWARD", new AllignWithPeg(AllignWithPeg::DRIVE_FORWARD));

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getDriver() {
   return driver;
}

std::shared_ptr<Joystick> OI::getCaptain() {

	return captain;}


// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
