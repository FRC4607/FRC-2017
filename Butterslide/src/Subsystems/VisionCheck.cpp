// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "VisionCheck.h"
#include "../RobotMap.h"
#include <thread>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

VisionCheck::VisionCheck() : Subsystem("VisionCheck") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	//highGoalPosition = RobotMap::visionCheckHighGoalPosition;

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	vnt = NetworkTable::GetTable("Vision");
	// Send our stored HSV values to the vision core.
	this->SendHSVEntriesToCore();
}

void VisionCheck::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void VisionCheck::PopulateHighGoalVals() {
	HighGoalPos = vnt->GetNumberArray("High Goal Pos", llvm::ArrayRef<double>());

	if (HighGoalPos.empty()) {
		SmartDashboard::PutString("Vision Tracker Status", "NO CONNECTION");
		HighGoalPos = llvm::ArrayRef<double>{0,0,0};
	}
	else {
		SmartDashboard::PutString("Vision Tracker Status", "ONLINE");
	}
}

float VisionCheck::HighGoalDistance() {
	return HighGoalPos[2];
}
float VisionCheck::HighGoalPosX() {
	return HighGoalPos[0];
}
float VisionCheck::HighGoalPosY() {
	return HighGoalPos[1];
}

void VisionCheck::DisplayValuesOnSD() {
	SmartDashboard::PutNumber("High Goal Distance", this->HighGoalDistance());
	SmartDashboard::PutNumber("High Goal X", this->HighGoalPosX());
	SmartDashboard::PutNumber("High Goal Y", this->HighGoalPosY());
}

void VisionCheck::CreateCameraEntriesOnSD() {
	SmartDashboard::PutNumber("H_MIN", 0);
	SmartDashboard::PutNumber("H_MAX", 255);
	SmartDashboard::PutNumber("S_MIN", 0);
	SmartDashboard::PutNumber("S_MAX", 255);
	SmartDashboard::PutNumber("V_MIN", 0);
	SmartDashboard::PutNumber("V_MAX", 255);
	SmartDashboard::PutNumber("Brightness (-1 Auto, 0-8)", -1);
	SmartDashboard::PutNumber("Contrast (-1 Auto, 0-8)", -1);
	SmartDashboard::PutNumber("Hue (-1 Auto, 0-11)", -1);
	SmartDashboard::PutNumber("Saturation (-1 Auto, 0-8)", -1);
	SmartDashboard::PutNumber("Gain (-1 Auto, 0-100)", -1);
	SmartDashboard::PutNumber("Exposure (-1 Auto, 0-100)", -1);
	SmartDashboard::PutNumber("White Balance (-1 Auto, 2800-6500)", -1);

	SmartDashboard::SetPersistent("H_MIN");
	SmartDashboard::SetPersistent("H_MAX");
	SmartDashboard::SetPersistent("S_MIN");
	SmartDashboard::SetPersistent("S_MAX");
	SmartDashboard::SetPersistent("V_MIN");
	SmartDashboard::SetPersistent("V_MAX");
	SmartDashboard::SetPersistent("Brightness (-1 Auto, 0-8)");
	SmartDashboard::SetPersistent("Contrast (-1 Auto, 0-8)");
	SmartDashboard::SetPersistent("Hue (-1 Auto, 0-11)");
	SmartDashboard::SetPersistent("Saturation (-1 Auto, 0-8)");
	SmartDashboard::SetPersistent("Gain (-1 Auto, 0-100)");
	SmartDashboard::SetPersistent("Exposure (-1 Auto, 0-100)");
	SmartDashboard::SetPersistent("White Balance (-1 Auto, 2800-6500)");
}

void VisionCheck::CheckForHSVUpdatesFromCore() {
	if (vnt->GetBoolean("HSVFromCore", false)) {
		// Have HSV Updates, pull them from NetworkTables.
		std::vector<double> HSVVals = vnt->GetNumberArray("HSVVals", -1);
		SmartDashboard::PutNumber("H_MIN", HSVVals.at(0));
		SmartDashboard::PutNumber("H_MAX", HSVVals.at(1));
		SmartDashboard::PutNumber("S_MIN", HSVVals.at(2));
		SmartDashboard::PutNumber("S_MAX", HSVVals.at(3));
		SmartDashboard::PutNumber("V_MIN", HSVVals.at(4));
		SmartDashboard::PutNumber("V_MAX", HSVVals.at(5));
		vnt->PutBoolean("HSVFromCore", false);
	}
}

void VisionCheck::SendHSVEntriesToCore() {
	vnt->PutBoolean("HSVFromSD", true);
	vnt->PutNumber("H_MIN", SmartDashboard::GetNumber("H_MIN", 0));
	vnt->PutNumber("H_MAX", SmartDashboard::GetNumber("H_MAX", 0));
	vnt->PutNumber("S_MIN", SmartDashboard::GetNumber("S_MIN", 0));
	vnt->PutNumber("S_MAX", SmartDashboard::GetNumber("S_MAX", 0));
	vnt->PutNumber("V_MIN", SmartDashboard::GetNumber("V_MIN", 0));
	vnt->PutNumber("V_MAX", SmartDashboard::GetNumber("V_MAX", 0));
}

void VisionCheck::SendCameraSettingsToCore() {
	vnt->PutBoolean("CamSettingsFromSD", true);
	vnt->PutNumber("Brightness", SmartDashboard::GetNumber("Brightness (-1 Auto, 0-8)", -1));
	vnt->PutNumber("Contrast", SmartDashboard::GetNumber("Contrast (-1 Auto, 0-8)", -1));
	vnt->PutNumber("Hue", SmartDashboard::GetNumber("Hue (-1 Auto, 0-11)", -1));
	vnt->PutNumber("Saturation", SmartDashboard::GetNumber("Saturation (-1 Auto, 0-8)", -1));
	vnt->PutNumber("Gain", SmartDashboard::GetNumber("Gain (-1 Auto, 0-100)", -1));
	vnt->PutNumber("Exposure", SmartDashboard::GetNumber("Exposure (-1 Auto, 0-100)", -1));
	vnt->PutNumber("WhiteBalance", SmartDashboard::GetNumber("White Balance (-1 Auto, 2800-6500)", -1));
}

std::thread VisionCheck::VisionThread() {
	return std::thread(&VisionCheck::DisplayCams, this);
}

void VisionCheck::HouseKeeping() {
	this->PopulateHighGoalVals();
	this->CheckForHSVUpdatesFromCore();
	this->DisplayValuesOnSD();
	this->SendHSVEntriesToCore();
	this->SendCameraSettingsToCore();
}

void VisionCheck::DisplayCams() {
	// Spin up CamDisplay objects for tracked image and hsv threshold.
	cam_displays.push_back(new CamDisplay(this->vnt, "ZED-threshold", "hg_thresh", 320, 180));
	cam_displays.push_back(new CamDisplay(this->vnt, "ZED-tracked", "hg_image", 320, 180));

}
