#include "../include/NullCommand.h"

namespace robovikes {
namespace testing {

NullCommand::NullCommand(frc::Subsystem* subsystem)
{
    Requires(subsystem);
}

bool NullCommand::IsFinished()
{ 
    return false;
};

} // testing
} // robovikes
