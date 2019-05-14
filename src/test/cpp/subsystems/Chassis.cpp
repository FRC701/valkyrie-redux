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

TEST_F(ChassisTest, Drive) {
    // Arrange
    using MockSpeedController = robovikes::testing::MockSpeedController;
    MockSpeedController left;
    MockSpeedController right;

    EXPECT_CALL(left, Set(1.0));
    EXPECT_CALL(right, Set(-1.0));
    Chassis chassis(kChassisSubsystemName, left, right);

    // Action
    constexpr double kDriveLeft = 1.0;
    constexpr double kDriveRight = 1.0;
    chassis.Drive(kDriveLeft, kDriveRight);

    // Assert
    // Mocks for left and right will assert
}

// Chassis should be 4 motors. 
TEST_F(ChassisTest, Drive4Motor) {
    // Arrange
    using MockSpeedController = robovikes::testing::MockSpeedController;
    MockSpeedController leftFront;
    MockSpeedController rightFront;
    MockSpeedController leftRear;
    MockSpeedController rightRear;
    frc::SpeedControllerGroup left(leftFront, leftRear);
    frc::SpeedControllerGroup right(rightFront, rightRear);

    EXPECT_CALL(leftFront, Set(1.0));
    EXPECT_CALL(rightFront, Set(-1.0));
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
TEST_F(ChassisTest, DriveDifferential) {
    // Arrange
    using SpeedController = robovikes::testing::MockSpeedController;
    SpeedController leftFront;
    SpeedController rightFront;
    SpeedController leftRear;
    SpeedController rightRear;

    constexpr double kDriveLeft = 0.5;
    constexpr double kDriveRight = 0.5;
    constexpr double kOutputLeft = 0.2399; // squared and scaled for the deadband
    constexpr double kOutputRight = -0.2399; // squared and scaled for the deadband

    EXPECT_CALL(leftFront, Set(DoubleNear(kOutputLeft, 0.0001)));
    EXPECT_CALL(rightFront, Set(DoubleNear(kOutputRight, 0.0001)));
    EXPECT_CALL(leftRear, Set(DoubleNear(kOutputLeft, 0.0001)));
    EXPECT_CALL(rightRear, Set(DoubleNear(kOutputRight, 0.0001)));

    frc::SpeedControllerGroup left(leftFront, leftRear);
    frc::SpeedControllerGroup right(rightFront, rightRear);
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