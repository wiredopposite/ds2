#include "DebugServer2/Host/File.h"

namespace ds2 {
namespace Host {

File::File(std::string const &, OpenFlags, uint32_t)
    : _fd(-1), _lastError(kErrorUnsupported) {}

File::~File() = default;

ErrorCode File::pread(ByteVector &, uint64_t &, uint64_t) {
  return kErrorUnsupported;
}

ErrorCode File::pwrite(ByteVector const &, uint64_t &, uint64_t) {
  return kErrorUnsupported;
}

ErrorCode File::fstat(ByteVector &) const { return kErrorUnsupported; }

ErrorCode File::chmod(std::string const &, uint32_t) {
  return kErrorUnsupported;
}

ErrorCode File::unlink(std::string const &) { return kErrorUnsupported; }

ErrorCode File::createDirectory(std::string const &, uint32_t) {
  return kErrorUnsupported;
}

ErrorCode File::fileSize(std::string const &, uint64_t &) {
  return kErrorUnsupported;
}

ErrorCode File::fileMode(std::string const &, uint32_t &) {
  return kErrorUnsupported;
}

} // namespace Host
} // namespace ds2
