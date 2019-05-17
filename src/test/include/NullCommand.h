// test/cpp/NullCommand.h

#pragma once

#include <frc/commands/Command.h>

namespace robovikes {
namespace testing {

class NullCommand : public frc::Command
{
public:
    explicit NullCommand(frc::Subsystem*);
protected:
    bool IsFinished() override;
};


} // testing
} // robovikes
