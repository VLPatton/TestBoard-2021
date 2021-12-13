/****************************************************************************
	Description:	Implements the CDrive control class.
	Classes:		CDrive
	Project:		2022 Testboard Robot Code
****************************************************************************/
#include "Drive.h"
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
	Description:	CDrive Constructor.
	Arguments:		None
	Derived From:	Nothing
******************************************************************************/
CDrive::CDrive(Joystick* pDriveController)
{
	// Initialize variable.
	m_bJoystickControl      = false;

	// Initialize objects.
	m_pDriveMotor1          = new CSparkMotion(nDriveMotor1);
	m_pDriveMotor2          = new CSparkMotion(nDriveMotor2);
	m_pPot1                 = new AnalogInput(nPotentiometer);
	m_pDriveController      = pDriveController;
	m_pRobotDrive           = new DifferentialDrive(*m_pDriveMotor1->GetMotorPointer(), *m_pDriveMotor2->GetMotorPointer());
}

/******************************************************************************
	Description:	CDrive Destructor.
	Arguments:		None
	Derived From:	Nothing
******************************************************************************/
CDrive::~CDrive()
{ 
	// Delete object pointers.
	delete m_pDriveMotor1;
	delete m_pDriveMotor2;
	delete m_pPot1;
	delete m_pRobotDrive;
	
	// Set pointer to null pointers.
	m_pDriveMotor1      = nullptr;
	m_pDriveMotor2      = nullptr;
	m_pPot1             = nullptr;
	m_pRobotDrive       = nullptr;
	m_pDriveController  = nullptr;
}

/******************************************************************************
	Description:	Initializes the CDrive class.
	Arguments:		None
	Returns:	    Nothing
******************************************************************************/
void CDrive::Init()
{
	// Set max acceleration to .65 seconds.
	m_pDriveMotor1->SetOpenLoopRampRate(dMotorOpenLoopRampRate);
	m_pDriveMotor2->SetOpenLoopRampRate(dMotorOpenLoopRampRate);

	// Clear persistant motor controller faults.
	m_pDriveMotor1->ClearStickyFaults();

	// Reset motor encoders.
	m_pDriveMotor1->ResetEncoderPosition();  
	m_pDriveMotor2->ResetEncoderPosition(); 

	// Don't let differential drive invert anything.
	m_pRobotDrive->SetRightSideInverted(true);
}


/******************************************************************************
	Description:	Update periodic functions, ran every 20ms.
	Arguments:		None
	Returns:    	Nothing
******************************************************************************/
void CDrive::Tick()
{
	// Check if joystick control is enable.
	if (m_bJoystickControl)
	{
		// Get joystick values
		double dXAxis = m_pDriveController->GetRawAxis(eRightAxisX);
		double dYAxis = m_pDriveController->GetRawAxis(eLeftAxisY);

		// Check if joystick is in deadzone.
		if (fabs(dXAxis) < dJoystickDeadzone)
		{
			dXAxis = 0;
		}

		if (fabs(dYAxis) < dJoystickDeadzone)
		{
			dYAxis = 0;
		}
		
		// Set drivetrain power to joystick values.
		m_pRobotDrive->ArcadeDrive(dYAxis, dXAxis, false);
	}
	
}

/******************************************************************************
	Description:	Enable Joystick control.
	Arguments:		None
	Returns:    	Nothing
******************************************************************************/
void CDrive::SetJoystickControl(bool bJoystickControl)
{
	m_bJoystickControl = bJoystickControl;
}