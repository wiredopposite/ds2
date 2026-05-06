#include "DebugServer2/Target/NXDK/Thread.h"

#define super ds2::Target::ThreadBase

namespace ds2 {
namespace Target {
namespace Xbox {

Thread::Thread(Process *process, ThreadId tid) : super(process, tid) {}

ErrorCode Thread::terminate() { return kErrorUnsupported; }

ErrorCode Thread::suspend() { return kErrorUnsupported; }

ErrorCode Thread::step(int, Address const &) { return kErrorUnsupported; }

ErrorCode Thread::resume(int, Address const &) { return kErrorUnsupported; }

ErrorCode Thread::readCPUState(Architecture::CPUState &) {
  return kErrorUnsupported;
}

ErrorCode Thread::writeCPUState(Architecture::CPUState const &) {
  return kErrorUnsupported;
}

void Thread::updateState() {}

} // namespace Xbox
} // namespace Target
} // namespace ds2
