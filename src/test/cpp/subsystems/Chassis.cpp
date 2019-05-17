// test/cpp/subsystems/Chassis.cpp
// Testing the Chassis Subsystem

#include "subsystems/Chassis.h"

#include "../../include/NullSpeedController.h"
#include "../../include/MockSpeedController.h"
#include <frc/SpeedControllerGroup.h>
#include <gtest/gtest.h>

namespace robovikes {
namespace valkyrie {
namespace testing {
namespace {

using ::testing::DoubleNear;

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

class MockChassisTest : public ::testing::Test
{
protected:
    using MockSpeedController = robovikes::testing::MockSpeedController;
    MockSpeedController mLeft;
    MockSpeedController mRight;

};

TEST_F(MockChassisTest, Drive) {
    EXPECT_CALL(mLeft, Set(1.0));
    EXPECT_CALL(mRight, Set(-1.0));
    Chassis chassis(kChassisSubsystemName, mLeft, mRight);

    // Action
    constexpr double kDriveLeft = 1.0;
    constexpr double kDriveRight = 1.0;
    chassis.Drive(kDriveLeft, kDriveRight);

    // Assert
    // Mocks for left and right will assert
}

// Chassis should be 4 motors. 
TEST_F(MockChassisTest, Drive4Motor) {
    // Arrange
    using MockSpeedController = robovikes::testing::MockSpeedController;
    MockSpeedController leftRear;
    MockSpeedController rightRear;
    frc::SpeedControllerGroup left(mLeft, leftRear);
    frc::SpeedControllerGroup right(mRight, rightRear);

    EXPECT_CALL(mLeft, Set(1.0));
    EXPECT_CALL(mRight, Set(-1.0));
    EXPECT_CALL(leftRear, Set(1.0));
    EXPECT_CALL(rightRear, Set(-1.0));
    Chassis chassis(kChassisSubsystemName, left, right);

    // Action
    constexpr double kDriveLeft = 1.0;
    constexpr double kDriveRight = 1.0;
    chassis.Drive(kDriveLeft, kDriveRight);

    // Assert
    // Mocks for left and right will assert
}

// And we would like to use the
// support of the DifferentialDrive capabilities. 
TEST_F(MockChassisTest, DriveDifferential) {
    // Arrange
    using SpeedController = robovikes::testing::MockSpeedController;
    SpeedController leftRear;
    SpeedController rightRear;

    constexpr double kDriveLeft = 0.5;
    constexpr double kDriveRight = 0.5;
    constexpr double kOutputLeft = 0.2399; // squared and scaled for the deadband
    constexpr double kOutputRight = -0.2399; // squared and scaled for the deadband

    EXPECT_CALL(mLeft, Set(DoubleNear(kOutputLeft, 0.0001)));
    EXPECT_CALL(mRight, Set(DoubleNear(kOutputRight, 0.0001)));
    EXPECT_CALL(leftRear, Set(DoubleNear(kOutputLeft, 0.0001)));
    EXPECT_CALL(rightRear, Set(DoubleNear(kOutputRight, 0.0001)));

    frc::SpeedControllerGroup left(mLeft, leftRear);
    frc::SpeedControllerGroup right(mRight, rightRear);
    Chassis chassis(kChassisSubsystemName, left, right);

    // Action
    chassis.Drive(kDriveLeft, kDriveRight);

    // Assert
    // Mocks for left and right will assert
}

} // namespace
} // namespace testing
} // namespace valkyrie
} // namespace robovikes