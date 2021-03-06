#pragma config(Motor,  port2,           leftFrontDrive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftBackDrive, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightFrontDrive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           rightBackDrive, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           puncher,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           flipper,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rubber,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//VEX Competition Control and Duration Settings (in seconds)
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(145)

#include "Vex_Competition_Includes.c"

//ArcadeBot
//Built for 2018 VEX Robotics Competition, "Turning Point"
//For WildStang B (111B) use only
//Developed by WhiteHoodHacker

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// This is used to execute robot commands before the start of the VEX Competition.
// Modify the code to add specific robot commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, etc.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control the robot during the autonomous phase of the VEX Competition.
// Modify the code to add robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{

		//Red Alliance Autonomous
			motor[leftFrontDrive] = -100;
			motor[leftBackDrive] = -100;
			motor[rightFrontDrive] = -100;
			motor[rightBackDrive] = -100;
			motor[puncher] = 100;
			wait1Msec(2000);
			motor[puncher] = 0;
			motor[leftFrontDrive] = 0;
			motor[leftBackDrive] = 0;
			motor[rightFrontDrive] = 0;
			motor[rightBackDrive] = 0;

		//Blue Alliance  Autonomous (collab with 2360)
		//	motor[leftFrontDrive] = 100;
		//	motor[leftBackDrive] = 100;
		//	motor[rightFrontDrive] = 100;
		//	motor[rightBackDrive] = 100;
		//	wait1Msec(300);
		//	motor[leftFrontDrive] = 0;
		//	motor[leftBackDrive] = 0;
		//	motor[rightFrontDrive] = 0;
		//	motor[rightBackDrive] = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control the robot during the user control phase of the VEX Competition.
// Modify the code to add robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	//Variables for puncher toggle button
	int puncherToggleState = 0;
	int puncherButtonPressed = 0;

	//Variables for intake toggle buttons
	int intakeForwardToggleState = 0;
	int intakeForwardButtonPressed = 0;
	int intakeReverseToggleState = 0;
	int intakeReverseButtonPressed = 0;

	//Variables for rubber toggle buttons
	int rubberToggleState = 0;
	int rubberButtonPressed = 0;

	while (true)
	{
		//Code for arcade drive (controlled by left joystick)
		motor[leftFrontDrive] = vexRT[Ch3] + vexRT[Ch4];
		motor[leftBackDrive] = vexRT[Ch3] + vexRT[Ch4];
		motor[rightFrontDrive] = vexRT[Ch3] - vexRT[Ch4];
		motor[rightBackDrive] = vexRT[Ch3] - vexRT[Ch4];

		//Code for intake (controlled by 8D button (forwards) and 7D button (reverse))
		if(vexRT[Btn8D] == 1)
		{
			if(! intakeForwardButtonPressed)
			{
				intakeForwardToggleState = 1 - intakeForwardToggleState;
				intakeForwardButtonPressed = 1;
			}
		}
		else
		{
			intakeForwardButtonPressed = 0;
		}
		if(intakeForwardToggleState)
		{
			intakeReverseToggleState = 0;
			intakeReverseButtonPressed = 0;
			motor[intake] = 50;
		}
		else
		{
			if(! intakeReverseToggleState)
			{
				motor[intake] = 0;
			}
		}

		if(vexRT[Btn7D] == 1)
		{
			if(! intakeReverseButtonPressed)
			{
				intakeReverseToggleState = 1 - intakeReverseToggleState;
				intakeReverseButtonPressed = 1;
			}
		}
		else
		{
			intakeReverseButtonPressed = 0;
		}
		if(intakeReverseToggleState)
		{
			intakeForwardToggleState = 0;
			intakeForwardButtonPressed = 0;
			motor[intake] = -50;
		}
		else
		{
			if(! intakeForwardToggleState)
			{
				motor[intake] = 0;
			}
		}

		//Code for puncher (controlled by 6D button)
		if(vexRT[Btn6D] == 1)
		{
			if(! puncherButtonPressed)
			{
				puncherToggleState = 1 - puncherToggleState;
				puncherButtonPressed = 1;
			}
		}
		else
		{
			puncherButtonPressed = 0;
		}
		if(puncherToggleState)
		{
			motor[puncher] = 100;
		}
		else
		{
			motor[puncher] = 0;
		}

		//Code for flipper (controlled by right joystick)
		motor[flipper] = vexRT[Ch2];

		//Code for rubber (controlled by 8R button)
		if(vexRT[Btn8R] == 1)
		{
			if(! rubberButtonPressed)
			{
				rubberToggleState = 1 - rubberToggleState;
				rubberButtonPressed = 1;
			}
		}
		else
		{
			rubberButtonPressed = 0;
		}
		if(rubberToggleState)
		{
			motor[rubber] = 100;
		}
		else
		{
			motor[rubber] = 0;
		}
	}
}
