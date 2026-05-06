#define STRINGIFY_H_INTERNAL
#include "DebugServer2/Utils/Stringify.h"

namespace ds2 {
namespace Utils {

char const *Stringify::WSAError(DWORD) { return "unsupported"; }

char const *Stringify::DebugEvent(DWORD) { return "unsupported"; }

char const *Stringify::ExceptionCode(DWORD) { return "unsupported"; }

} // namespace Utils
} // namespace ds2
