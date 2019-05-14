/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Drive/DifferentialDrive.h>
#include <frc/SpeedController.h>

namespace robovikes {
namespace valkyrie {

class Chassis : public frc::Subsystem {
public:
  using SpeedController = frc::SpeedController;
  Chassis(const wpi::Twine& name, SpeedController& left, SpeedController& right);
  void InitDefaultCommand() override;

  void Drive(double left, double right);

private:
  SpeedController& mLeft;
  SpeedController& mRight;
  frc::DifferentialDrive mDrive;
};

} // valkyrie
} // robovikes
