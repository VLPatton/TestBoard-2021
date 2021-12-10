/****************************************************************************
    Description:	Defines the CDrive control class.
    Classes:		CDrive
    Project:		2021 Infinite Recharge Robot Code.
    Copyright 2021 First Team 3284 - Camdenton LASER Robotics.
****************************************************************************/
#ifndef Drive_h
#define Drive_h

#include "IOMap.h"
#include "SparkMotion.h"

#include <rev/CANSparkMax.h>
#include <frc/controller/PIDController.h>
#include <frc/AnalogInput.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>
#include <frc/drive/DifferentialDrive.h>

using namespace rev;
using namespace frc;

// Declare constants
const double dMotorOpenLoopRampRate             = 0.650;
const double dJoystickDeadzone                  = 0.100; 
///////////////////////////////////////////////////////////////////////////////
class CDrive
{
public:
    // Declare class methods.
    CDrive(Joystick *pDriveController);
    ~CDrive();
    void Init();
    void Tick();
    void SetJoystickControl(bool bJoystickControl);

private:
    // Declare class objects and variables.
    bool                                    m_bJoystickControl;
    CSparkMotion*                           m_pDriveMotor1;
    CSparkMotion*                           m_pDriveMotor2;
    AnalogInput*                            m_pPot1;
    Joystick*                               m_pDriveController;
    DifferentialDrive*                      m_pRobotDrive;
};
///////////////////////////////////////////////////////////////////////////////
#endif