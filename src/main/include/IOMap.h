/****************************************************************************
    Description:	Defines the 2020 Infinite Recharge Robot I/O map.
    Classes:		None
    Project:		2020 Infinite Recharge Robot Code.
    Copyright 2020 First Team 3284 - Camdenton LASER Robotics.
****************************************************************************/
#ifndef IOMap_h
#define IOMap_h
/////////////////////////////////////////////////////////////////////////////

// Solenoid Channels.
const int nSolenoid1                    =   0;      // Solenoid channel for solenoid 1.
const int nSolenoid2                    =   1;      // Solenoid channel for solenoid 2.

// CAN Device IDs.
const int nDriveMotor1                  =   2;      // CAN ID for Right NEO drive motor.
const int nDriveMotor2                  =   7;      // CAN ID for Left NEO drive motor.
const int nAuxMotor1                    =   6;      // CAN ID for NEO 550 motor.
const int nAuxMotor2                    =   1;      // CAN ID for Falcon500 motor.
const int nAuxMotor3                    =   5;      // CAN ID for BAG motor.

// PWM Channels.
const int nBlinkinID					=	1;		// PWM channel for Blinkin LED driver
const int nHoodServo					= 	0;		// PWM channel for Hood actuation servo

// Relay Channels.

// Analog Channels.
const int nPotentiometer                =   0;      // Analog channel for pot.

// Digital Channels.
const int nOpticalSensor                =   0;      // Digital channel for beam-break optical sensor.
const int nHoodEncoderChannelA			=	4;		// Digital channel Encoder clock A signal for hood servo
const int nHoodEncoderChannelB			=	5;		// Digital channel Encoder clock B signal for hood servo

// Xbox Controller Button Assignments.
enum XboxButtons 		{eButtonA = 1, eButtonB, eButtonX, eButtonY, eButtonLB, eButtonRB, eBack, eStart, eButtonLS, eButtonRS};
// Xbox Controller Axis Assignments.
enum XboxAxis			{eLeftAxisX = 0, eLeftAxisY, eLeftTrigger, eRightTrigger, eRightAxisX, eRightAxisY};
// Logitech Flight Stick Button Assignments.
enum LogButtons	 		{eButtonTrigger = 1, eButton2, eButton3, eButton4, eButton5, eButton6, eButton7, eButton8, eButton9, eButton10, eButton11, eButton12};
// Shared Robot states for Motion.
enum State {eIdle, eHomingReverse, eHomingForward, eFinding, eManualForward, eManualReverse};
/////////////////////////////////////////////////////////////////////////////
#endif