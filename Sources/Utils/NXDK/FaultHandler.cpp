#include "DebugServer2/Utils/Log.h"

namespace {
struct FaultHandler {
  FaultHandler() { DS2LOG(Debug, "fault handler not available on nxdk build"); }
};

FaultHandler instance;
} // namespace
