/****************************************************************************
    Description:	Defines the CAuxAttachment control class.
    Classes:		CAuxAttachment
    Project:		2022 Testboard Robot Code
****************************************************************************/
#ifndef AuxAttachment_h
#define AuxAttachment_h

#include "IOMap.h"

#include <frc/Solenoid.h>
#include <ctre/Phoenix.h>
#include <rev/CANSparkMax.h>
#include <frc/controller/PIDController.h>
#include <frc/smartdashboard/SmartDashboard.h>

using namespace ctre;
using namespace rev;
using namespace frc;
///////////////////////////////////////////////////////////////////////////////
class CAuxAttachment
{
public:
    // Declare class methods.
    CAuxAttachment();
    ~CAuxAttachment();
    void Init();
    void Tick();

private:
    // Declare class objects and variables.
    CANSparkMax*                            m_pAuxMotor1;       // NEO 550
    WPI_TalonFX*                            m_pAuxMotor2;       // Falcon 500
    WPI_TalonSRX*                           m_pAuxMotor3;       // BAG Motor
    Solenoid*                               m_pActuator1;
};
///////////////////////////////////////////////////////////////////////////////
#endif