// test/cpp/subsystems/Chassis.cpp
// Testing the Chassis Subsystem

#include "subsystems/Chassis.h"

#include <gtest/gtest.h>

namespace robovikes {
namespace valkyrie {
namespace testing {
namespace {

TEST(ChassisTest, ConstructSubsystem) {
    Chassis chassis;
}


TEST(ChassisTest, ChassisName) {
    // Arrange
    Chassis chassis;

    // Action
    std::string subsystemName = chassis.GetName();
    // Assert or Expect
    EXPECT_EQ(subsystemName, "Chassis");
}

} // namespace
} // namespace testing
} // namespace valkyrie
} // namespace robovikes