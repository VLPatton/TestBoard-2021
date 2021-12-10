/****************************************************************************
    Description:	Defines the CAuxAttachment control class.
    Classes:		CAuxAttachment
    Project:		2021 Infinite Recharge Robot Code.
    Copyright 2021 First Team 3284 - Camdenton LASER Robotics.
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
    CANSparkMax*                            m_pAuxMotor1;
    WPI_TalonFX*                            m_pAuxMotor2;
    WPI_TalonSRX*                           m_pAuxMotor3;
    Solenoid*                               m_pActuator1;
};
///////////////////////////////////////////////////////////////////////////////
#endif