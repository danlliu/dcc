
#include "compiler_context.h"

using namespace dlang;

std::ostream& operator<<(std::ostream& o, const VirtualRegister& vr) {
  if (vr.id == 0)
    return o << "[ Constant " << vr.constValue << " ]";
  else
    return o << "[ VirtualRegister " << vr.id << " ]";
}

std::ostream& operator<<(std::ostream& o, const LivenessManager& lm) {
  o << "C";
  for (unsigned i = 1; i < lm.getSize(); ++i) o << lm.isLive(i);
  return o;
}
