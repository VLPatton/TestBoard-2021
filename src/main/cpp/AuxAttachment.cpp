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
	// Set max acceleration to .65 seconds.
	m_pAuxMotor1->SetOpenLoopRampRate(dMotorOpenLoopRampRate);
	m_pAuxMotor2->ConfigOpenloopRamp(dMotorOpenLoopRampRate);
	m_pAuxMotor3->ConfigOpenloopRamp(dMotorOpenLoopRampRate);
}

/******************************************************************************
	Description:	Update periodic functions, ran every 20ms.
	Arguments:		None
	Returns:	    Nothing
******************************************************************************/
void CAuxAttachment::Tick()
{
	if (m_pJoystick->GetRawButtonReleased(eButtonA)) {
		m_pAuxMotor2->Set((double)0);
	}
	if (m_pJoystick->GetRawButtonPressed(eButtonA)) {
		m_pAuxMotor2->Set((double)1);
	}
}