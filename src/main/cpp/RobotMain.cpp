/******************************************************************************
    Description:	2021 Infinite Recharge Robot Control Software.
    Classes:		CRobotMain
    Project:		2021 Test Board Code
    Copyright 2021 First Team 3284 - Camdenton LASER Robotics.
******************************************************************************/
#include "RobotMain.h"

#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
    Description:	CRobotMain Constructor.
    Arguments:		None
    Derived From:	TimedRobot
******************************************************************************/
CRobotMain::CRobotMain()
{
    // Initialize objects and variables.
    m_pJoystick                     = new Joystick(0);
    m_pDrive                        = new CDrive(m_pJoystick);
}

/******************************************************************************
    Description:	CRobotMain Destructor.
    Arguments:		None
    Derived From:	TimedRobot
******************************************************************************/
CRobotMain::~CRobotMain()
{

}


/****************************************************************************
    Description:	Ran on initial startup of the robot.
    Arguments: 		None
    Returns: 		  Nothing
****************************************************************************/
void CRobotMain::RobotInit() 
{
  // Setup autonomous chooser.
  m_pAutonomousChooser->SetDefaultOption("Autonomous Idle", "Autonomous Idle");
  m_pAutonomousChooser->AddOption("Alliance Trench", "Alliance Trench");
  m_pAutonomousChooser->AddOption("Front Shield Generator", "Front Shield Generator");
  m_pAutonomousChooser->AddOption("Side Shield Generator", "Side Sheild Generator");
  m_pAutonomousChooser->AddOption("Opposing Trench", "Opposing Trench");
  m_pAutonomousChooser->AddOption("Power Port", "Power Port");
  m_pAutonomousChooser->AddOption("Test Path", "Test Path");
  SmartDashboard::PutData(m_pAutonomousChooser);
}

/******************************************************************************
    Description:	Runs every 20ms in a loop after the robot has started.
    Arguments:	 	None
    Returns: 		  Nothing
******************************************************************************/
void CRobotMain::RobotPeriodic()
{

}


/******************************************************************************
    Description:	Ran only once, after the robot has entered Autonomous mode.
    Arguments:	 	None
    Returns: 		  Nothing
******************************************************************************/
void CRobotMain::AutonomousInit() 
{

}

/******************************************************************************
    Description:	Runs every 20ms in a loop after the robot has entered
                    Autonomous mode.
    Arguments:	 	None
    Returns: 		  Nothing
******************************************************************************/
void CRobotMain::AutonomousPeriodic() 
{

}

/******************************************************************************
    Description:	Ran only once, after the robot has entered Teleop mode.
    Arguments:	 	None
    Returns: 		  Nothing
******************************************************************************/
void CRobotMain::TeleopInit()
{
    // Initialize classes.
    m_pDrive->Init();
}

/******************************************************************************
    Description:	Runs every 20ms in a loop after the robot has entered
                    Teleop mode.
    Arguments:	 	None
    Returns: 		  Nothing
******************************************************************************/
void CRobotMain::TeleopPeriodic()
{
    m_pDrive->Tick();
}

/******************************************************************************
    Description:	Ran only once, after the robot has entered Disabled mode.
    Arguments:	 	None
    Returns: 		  Nothing
******************************************************************************/
void CRobotMain::DisabledInit()
{

}

/******************************************************************************
    Description:	Runs every 20ms in a loop after the robot has entered
                    Teleop mode.
    Arguments:	 	None
    Returns: 		  Nothing
******************************************************************************/
void CRobotMain::DisabledPeriodic()
{

}

/******************************************************************************
    Description:	Ran only once, after the robot has entered Teleop mode.
    Arguments:	 	None
    Returns: 		  Nothing
******************************************************************************/
void CRobotMain::TestInit() 
{

}

/******************************************************************************
    Description:	Runs every 20ms in a loop after the robot has entered
                    Teleop mode.
    Arguments:	 	None
    Returns: 		  Nothing
******************************************************************************/
void CRobotMain::TestPeriodic()
{

}

#ifndef RUNNING_FRC_TESTS
int main() {
  return StartRobot<CRobotMain>();
}
#endif
