#include "DebugServer2/Target/NXDK/Process.h"
#include "DebugServer2/Host/Platform.h"
#include "DebugServer2/Target/NXDK/Thread.h"

#define super ds2::Target::ProcessBase

namespace ds2 {
namespace Target {
namespace Xbox {

Process::Process() : super() {}

Process::~Process() { detach(); }

ErrorCode Process::initialize(ProcessId pid, uint32_t flags) {
  CHK(super::initialize(pid, flags));

  if (_threads.empty()) {
    _currentThread = new Thread(this, static_cast<ThreadId>(1));
  }

  return kSuccess;
}

ErrorCode Process::detach() {
  cleanup();
  _flags = 0;
  _pid = kAnyProcessId;
  _terminated = true;
  return kSuccess;
}

ErrorCode Process::interrupt() { return kErrorUnsupported; }

ErrorCode Process::terminate() {
  _terminated = true;
  return kSuccess;
}

bool Process::isAlive() const { return !_terminated; }

ErrorCode Process::readString(Address const &, std::string &, size_t,
                              size_t *) {
  return kErrorUnsupported;
}

ErrorCode Process::readMemory(Address const &, void *, size_t, size_t *) {
  return kErrorUnsupported;
}

ErrorCode Process::writeMemory(Address const &, void const *, size_t, size_t *) {
  return kErrorUnsupported;
}

ErrorCode Process::enumerateSharedLibraries(
    std::function<void(SharedLibraryInfo const &)> const &) {
  return kErrorUnsupported;
}

ErrorCode Process::wait() { return kErrorUnsupported; }

ErrorCode Process::allocateMemory(size_t, uint32_t, uint64_t *) {
  return kErrorUnsupported;
}

ErrorCode Process::deallocateMemory(uint64_t, size_t) {
  return kErrorUnsupported;
}

ErrorCode Process::getMemoryRegionInfo(Address const &, MemoryRegionInfo &) {
  return kErrorUnsupported;
}

ErrorCode Process::updateInfo() {
  _info.clear();
  _info.pid = _pid;
  _info.cpuType = kCPUTypeX86;
  _info.cpuSubType = kCPUSubTypeX86_ALL;
  _info.endian = kEndianLittle;
  _info.pointerSize = sizeof(void *);
  _info.osType = "nxdk";
  _info.osVendor = "microsoft";
  return kSuccess;
}

Target::Process *Process::Create(Host::ProcessSpawner &) {
  return nullptr;
}

Target::Process *Process::Attach(ProcessId pid) {
  auto process = make_protected_unique();
  if (process->initialize(pid, kFlagAttachedProcess) != kSuccess) {
    return nullptr;
  }
  return process.release();
}

} // namespace Xbox
} // namespace Target
} // namespace ds2
