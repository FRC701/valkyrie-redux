// test/cpp/subsystems/Chassis.cpp
// Testing the Chassis Subsystem

#include "subsystems/Chassis.h"

#include <gtest/gtest.h>

namespace robovikes {
namespace valkyrie {
namespace testing {
namespace {

// Use Twine instead of std::string because it's WPI.
const wpi::Twine kChassisSubsystemName = "Chassis";

TEST(ChassisTest, ConstructSubsystem) {
    Chassis chassis(kChassisSubsystemName);
}

TEST(ChassisTest, ChassisName) {
    // Arrange
    Chassis chassis(kChassisSubsystemName);

    // Action
    std::string subsystemName = chassis.GetName();
    // Assert or Expect
    EXPECT_EQ(subsystemName, "Chassis");
}

TEST(ChassisTest, Drive) {
    // Arrange
    Chassis chassis(kChassisSubsystemName);

    // Action
    constexpr double kDriveLeft = 1.0;
    constexpr double kDriveRight = 1.0;
    chassis.Drive(kDriveLeft, kDriveRight);

    // Assert or Expect
    // TODO: How to test? gmock?
    FAIL();
}


} // namespace
} // namespace testing
} // namespace valkyrie
} // namespace robovikes