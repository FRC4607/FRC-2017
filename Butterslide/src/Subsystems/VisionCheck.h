// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef VISION_CHECK_H
#define VISION_CHECK_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "opencv2/core.hpp"

/**
 *
 *
 * @author ExampleAuthor
 */
class VisionCheck: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<DigitalInput> highGoalPosition;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	llvm::ArrayRef<double> HighGoalPos;
	std::shared_ptr<NetworkTable> vnt;

public:
	VisionCheck();
	void InitDefaultCommand();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

	void PopulateHighGoalVals();
	float HighGoalDistance();
	float HighGoalPosX();
	float HighGoalPosY();

	void DisplayValuesOnSD();
	void CreateHSVEntriesOnSD();
	void SendHSVEntriesToTX1();
};

#endif
