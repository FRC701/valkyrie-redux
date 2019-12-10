/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Chassis.h"

namespace robovikes {
namespace valkyrie {

Chassis::Chassis(
    const wpi::Twine& name
  , SpeedController& left
  , SpeedController& right) 
  : Subsystem(name) 
  , mLeft(left)
  , mRight(right)
  , mDrive(left, right)
{}

void Chassis::InitDefaultCommand() 
{
}

void Chassis::Drive(double left, double right) 
{
  mDrive.TankDrive(left, right);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

} // valkyrie
} // robovikes