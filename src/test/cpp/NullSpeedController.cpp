#include "../include/NullSpeedController.h"

namespace robovikes {
namespace testing {

  /**
   * Common interface for setting the speed of a speed controller.
   *
   * @param speed The speed to set.  Value should be between -1.0 and 1.0.
   */
  void NullSpeedController::Set(double speed)
  {

  }

  /**
   * Common interface for getting the current set speed of a speed controller.
   *
   * @return The current set speed.  Value is between -1.0 and 1.0.
   */
  double NullSpeedController::Get() const
  {
      return 0.;
  }

  /**
   * Common interface for inverting direction of a speed controller.
   *
   * @param isInverted The state of inversion, true is inverted.
   */
  void NullSpeedController::SetInverted(bool isInverted) 
  {

  }

  /**
   * Common interface for returning the inversion state of a speed controller.
   *
   * @return isInverted The state of inversion, true is inverted.
   */
  bool NullSpeedController::GetInverted() const
  {
      return false;
  }

  /**
   * Common interface for disabling a motor.
   */
  void NullSpeedController::Disable()
  {

  }

  /**
   * Common interface to stop the motor until Set is called again.
   */
  void NullSpeedController::StopMotor()
  {

  }

  /**
   * From PIDOutput
   */
  void NullSpeedController::PIDWrite(double output)
  {

  }

} // testing
} // robovikes
