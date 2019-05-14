// test/cpp/subsystems/Chassis.cpp
// Testing the Chassis Subsystem

#include "subsystems/Chassis.h"

#include "../../include/NullSpeedController.h"
#include "../../include/MockSpeedController.h"
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
    using MockSpeedController = robovikes::testing::MockSpeedController;
    MockSpeedController left;
    MockSpeedController right;

    EXPECT_CALL(left, Set(1.0));
    EXPECT_CALL(right, Set(1.0));
    Chassis chassis(kChassisSubsystemName, left, right);

    // Action
    constexpr double kDriveLeft = 1.0;
    constexpr double kDriveRight = 1.0;
    chassis.Drive(kDriveLeft, kDriveRight);

    // Assert
    // Mocks for left and right will assert
}


} // namespace
} // namespace testing
} // namespace valkyrie
} // namespace robovikes