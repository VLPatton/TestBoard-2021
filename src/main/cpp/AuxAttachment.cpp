/****************************************************************************
	Description:	Implements the CAuxAttachment control class.
	Classes:		CAuxAttachment
	Project:		2022 Testboard Robot Code
****************************************************************************/
#include "AuxAttachment.h"
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
	Description:	CAuxAttachment Constructor.
	Arguments:		None
	Derived From:	Nothing
******************************************************************************/
CAuxAttachment::CAuxAttachment(Joystick* pJoystick)
{
	m_pAuxMotor1			= new CANSparkMax(nAuxMotor1, CANSparkMax::MotorType::kBrushless);
	m_pAuxMotor2			= new WPI_TalonFX(nAuxMotor2);
	m_pAuxMotor3			= new WPI_TalonSRX(nAuxMotor3);

	m_pJoystick = pJoystick;
}

/******************************************************************************
	Description:	CAuxAttachment Destructor.
	Arguments:		None
	Derived From:	Nothing
******************************************************************************/
CAuxAttachment::~CAuxAttachment()
{
	// Delete pointers
	delete m_pAuxMotor1;
	delete m_pAuxMotor2;
	delete m_pAuxMotor3;

	// Set to nullptr's
	m_pAuxMotor1	= nullptr;
	m_pAuxMotor2	= nullptr;
	m_pAuxMotor3	= nullptr;
}

/******************************************************************************
	Description:	Initializes the AuxAttachment class.
	Arguments:		None
	Returns:	    Nothing
******************************************************************************/
void CAuxAttachment::Init()
{
	// Set max acceleration to .65 seconds and clear faults.
	m_pAuxMotor1->SetOpenLoopRampRate(dMotorOpenLoopRampRate);	// NEO 550
	m_pAuxMotor1->ClearFaults();
	m_pAuxMotor1->ClearError();

	m_pAuxMotor2->ConfigOpenloopRamp(dMotorOpenLoopRampRate);	// Falcon500
	m_pAuxMotor2->ClearStickyFaults();

	m_pAuxMotor3->ConfigOpenloopRamp(dMotorOpenLoopRampRate);	// BAG motor
	m_pAuxMotor3->ClearStickyFaults();
}

/******************************************************************************
	Description:	Update periodic functions, ran every 20ms.
	Arguments:		None
	Returns:	    Nothing
******************************************************************************/
void CAuxAttachment::Tick()
{
	if (m_pJoystick->GetRawButtonPressed(eButtonA)) {
		m_pAuxMotor2->Set((double)1);					// If button A is pressed, set speed to 100%
	}
	if (m_pJoystick->GetRawButtonReleased(eButtonA)) {
		m_pAuxMotor2->Set((double)0);					// If button A is released, set speed to 0%
	}
}