
#ifndef _DCC_COMPILER_CONTEXT_H
#define _DCC_COMPILER_CONTEXT_H

#include <map>
#include <stack>
#include <string>

#include "arm64.h"
#include "macros.h"
#include "register_allocator.h"

namespace dlang {

struct VirtualRegister {
  // id = 0 => constant
  unsigned id = 0;
  int constValue = 0;

  inline bool isConst() { return id == 0; }
  inline ARM64Register toReg(const RegisterAllocator& ra) {
    if (id == 0)
      return CONST(constValue);
    else
      return REG(static_cast<unsigned>(ra.getAllocationFor(id)));
  }
};

class VariableScopeManager {
 public:
  inline VirtualRegister add(const std::string& s) { if (!defined(s)) variables[s] = {nextVR++}; return variables[s]; }
  inline VirtualRegister addTemp() { return {nextVR++}; }
  inline bool defined(const std::string& s) { return variables.find(s) != end(variables); }
  inline VirtualRegister lookup(const std::string& s) { return variables[s]; }
  inline void pushContext() { scopes.push({}); }
  inline void popContext() {
    for (auto it : scopes.top()) variables.erase(it);
    scopes.pop();
  }
  inline unsigned getNumVariables() { return nextVR; }
 private:
  std::map<std::string, VirtualRegister> variables;
  std::stack<std::vector<std::map<std::string, VirtualRegister>::iterator>> scopes;
  unsigned nextVR = 1;
};

class LivenessManager {
 public:
  LivenessManager() = default;
  LivenessManager(unsigned size) : live(size) {};
  inline size_t getSize() const { return size(live); }
  inline void resize(unsigned size) { live.resize(size); }
  inline bool isLive(unsigned id) const { return (id != 0) && live[id]; }
  inline void setLive(unsigned id) { if (id != 0) live[id] = true; }
  inline void setNotLive(unsigned id) { if (id != 0) live[id] = false; }

  LivenessManager& operator&=(const LivenessManager& other) {
    if (size(live) != size(other.live)) ERR_AND_EXIT("Trying to | together LivenessManagers of different sizes");
    for (unsigned i = 0; i < size(live); ++i) {
      live[i] = live[i] && other.live[i];
    }
    return *this;
  }

  LivenessManager& operator|=(const LivenessManager& other) {
    if (size(live) != size(other.live)) ERR_AND_EXIT("Trying to | together LivenessManagers of different sizes");
    for (unsigned i = 0; i < size(live); ++i) {
      live[i] = live[i] || other.live[i];
    }
    return *this;
  }
 private:
  std::vector<bool> live;
};

}

std::ostream& operator<<(std::ostream& o, const dlang::VirtualRegister& vr);
std::ostream& operator<<(std::ostream& o, const dlang::LivenessManager& lm);

#endif
