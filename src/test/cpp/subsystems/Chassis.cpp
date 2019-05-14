// test/cpp/subsystems/Chassis.cpp
// Testing the Chassis Subsystem

#include "subsystems/Chassis.h"

#include "../../include/NullSpeedController.h"
#include <gtest/gtest.h>

namespace robovikes {
namespace valkyrie {
namespace testing {
namespace {

// Use Twine instead of std::string because it's WPI.
const wpi::Twine kChassisSubsystemName = "Chassis";

class ChassisTest : public ::testing::Test
{
protected:
    using SpeedController = robovikes::testing::NullSpeedController;
    SpeedController mLeft;
    SpeedController mRight;

};

TEST_F(ChassisTest, ConstructSubsystem) {
    Chassis chassis(kChassisSubsystemName, mLeft, mRight);
}


TEST_F(ChassisTest, ChassisName) {
    // Arrange
    Chassis chassis(kChassisSubsystemName, mLeft, mRight);

    // Action
    std::string subsystemName = chassis.GetName();
    // Assert or Expect
    EXPECT_EQ(subsystemName, "Chassis");
}

TEST_F(ChassisTest, Drive) {
    // Arrange
    Chassis chassis(kChassisSubsystemName, mLeft, mRight);

    // Action
    constexpr double kDriveLeft = 1.0;
    constexpr double kDriveRight = 1.0;
    chassis.Drive(kDriveLeft, kDriveRight);

    // Assert or Expect
    // TODO: How to test? gmock?
    // Chassis will have two SpeedControllers, left and right
    // A mock speed controller can tell us if the speed controller was used.
    FAIL();
}


} // namespace
} // namespace testing
} // namespace valkyrie
} // namespace robovikes