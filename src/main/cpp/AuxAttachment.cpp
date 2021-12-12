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
CAuxAttachment::CAuxAttachment()
{
    m_pAuxMotor1            = new CANSparkMax(nAuxMotor1, CANSparkMax::MotorType::kBrushless);
    m_pAuxMotor2            = new WPI_TalonFX(nAuxMotor2);
    m_pAuxMotor3            = new WPI_TalonSRX(nAuxMotor3);
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
    m_pAuxMotor1    = nullptr;
    m_pAuxMotor2    = nullptr;
    m_pAuxMotor3    = nullptr;
}

/******************************************************************************
    Description:	Initializes the AuxAttachment class.
    Arguments:		None
    Returns:	    Nothing
******************************************************************************/
void CAuxAttachment::Init()
{

}

/******************************************************************************
    Description:	Update periodic functions, ran every 20ms.
    Arguments:		None
    Returns:	    Nothing
******************************************************************************/
void CAuxAttachment::Tick()
{
    
}