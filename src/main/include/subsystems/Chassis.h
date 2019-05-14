/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>

namespace robovikes {
namespace valkyrie {

class Chassis : public frc::Subsystem {
public:
  Chassis(const wpi::Twine& name);
  void InitDefaultCommand() override;

  void Drive(double left, double right);

private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

};

} // valkyrie
} // robovikes
