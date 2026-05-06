#include "DebugServer2/Host/Platform.h"
#include "DebugServer2/Utils/Log.h"

#include <cstdio>

namespace ds2 {
namespace Host {

void Platform::Initialize() { setvbuf(stdout, nullptr, _IONBF, 0); }

size_t Platform::GetPageSize() { return 4096; }

const char *Platform::GetHostName(bool) { return "xbox"; }

char const *Platform::GetOSTypeName() { return "nxdk"; }

char const *Platform::GetOSVendorName() { return "microsoft"; }

char const *Platform::GetOSVersion() { return "unknown"; }

char const *Platform::GetOSBuild() { return "unknown"; }

char const *Platform::GetOSKernelVersion() { return "unknown"; }

bool Platform::GetUserName(UserId const &, std::string &) { return false; }

bool Platform::GetGroupName(GroupId const &, std::string &) { return false; }

int Platform::OpenFile(std::string const &, uint32_t, uint32_t) { return -1; }

bool Platform::CloseFile(int) { return false; }

bool Platform::IsFilePresent(std::string const &) { return false; }

std::string Platform::GetWorkingDirectory() { return std::string("/"); }

bool Platform::SetWorkingDirectory(std::string const &) { return false; }

ds2::ProcessId Platform::GetCurrentProcessId() { return 1; }

const char *Platform::GetSelfExecutablePath() { return "default.xbe"; }

bool Platform::GetCurrentEnvironment(EnvironmentBlock &env) {
  env.clear();
  return true;
}

ErrorCode Platform::TranslateError(DWORD) { return ds2::kErrorUnsupported; }

ErrorCode Platform::TranslateError() { return ds2::kErrorUnsupported; }

bool Platform::GetProcessInfo(ProcessId pid, ProcessInfo &info) {
  info.clear();
  info.pid = pid;
  info.name = "xbox";
  info.cpuType = kCPUTypeX86;
  info.cpuSubType = kCPUSubTypeX86_ALL;
  info.endian = kEndianLittle;
  info.pointerSize = sizeof(void *);
  info.osType = "nxdk";
  info.osVendor = "microsoft";
  return true;
}

void Platform::EnumerateProcesses(
    bool, UserId const &, std::function<void(ProcessInfo const &)> const &cb) {
  ProcessInfo info;
  GetProcessInfo(GetCurrentProcessId(), info);
  cb(info);
}

bool Platform::TerminateProcess(ProcessId) { return false; }

std::string Platform::GetThreadName(ProcessId, ThreadId) { return std::string(); }

bool Platform::GetExecutableFileBuildID(std::string const &, ByteVector &) {
  return false;
}

} // namespace Host
} // namespace ds2
