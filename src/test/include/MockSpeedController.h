// test/cpp/MockSpeedController.h

#pragma once

#include <frc/SpeedController.h>

#include <gmock/gmock.h>

namespace robovikes {
namespace testing {

class MockSpeedController : public frc::SpeedController
{
public:
  /**
   * Common interface for setting the speed of a speed controller.
   *
   * @param speed The speed to set.  Value should be between -1.0 and 1.0.
   */
  MOCK_METHOD1(Set, void (double speed));

  /**
   * Common interface for getting the current set speed of a speed controller.
   *
   * @return The current set speed.  Value is between -1.0 and 1.0.
   */
  MOCK_CONST_METHOD0(Get, double ());

  /**
   * Common interface for inverting direction of a speed controller.
   *
   * @param isInverted The state of inversion, true is inverted.
   */
  MOCK_METHOD1(SetInverted, void (bool isInverted));

  /**
   * Common interface for returning the inversion state of a speed controller.
   *
   * @return isInverted The state of inversion, true is inverted.
   */
  MOCK_CONST_METHOD0(GetInverted, bool ());

  /**
   * Common interface for disabling a motor.
   */
  MOCK_METHOD0(Disable, void ());

  /**
   * Common interface to stop the motor until Set is called again.
   */
  MOCK_METHOD0(StopMotor, void ());

  /**
   * From PIDOutput
   */
  MOCK_METHOD1(PIDWrite, void (double output));
};

} // testing
} // robovikes
