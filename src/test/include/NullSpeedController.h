// test/cpp/NullSpeedController.h

#pragma once

#include <frc/SpeedController.h>

namespace robovikes {
namespace testing {

class NullSpeedController : public frc::SpeedController
{
public:
    NullSpeedController() = default;
    ~NullSpeedController() = default;

  /**
   * Common interface for setting the speed of a speed controller.
   *
   * @param speed The speed to set.  Value should be between -1.0 and 1.0.
   */
  void Set(double speed) override;

  /**
   * Common interface for getting the current set speed of a speed controller.
   *
   * @return The current set speed.  Value is between -1.0 and 1.0.
   */
  double Get() const override;

  /**
   * Common interface for inverting direction of a speed controller.
   *
   * @param isInverted The state of inversion, true is inverted.
   */
  void SetInverted(bool isInverted)  override;

  /**
   * Common interface for returning the inversion state of a speed controller.
   *
   * @return isInverted The state of inversion, true is inverted.
   */
  bool GetInverted() const override;

  /**
   * Common interface for disabling a motor.
   */
  void Disable() override;

  /**
   * Common interface to stop the motor until Set is called again.
   */
  void StopMotor() override;

  /**
   * From PIDOutput
   */
  void PIDWrite(double output) override;
};

} // testing
} // robovikes
