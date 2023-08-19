
#ifndef _DCC_REGISTER_ALLOCATOR_H
#define _DCC_REGISTER_ALLOCATOR_H

#include <vector>

namespace dlang {
  class LivenessManager;
}

class RegisterAllocator {
 public:
  RegisterAllocator(unsigned numRegisters, unsigned numVirtRegisters)
    : m_numRegisters(numRegisters)
    , m_numVirtRegisters(numVirtRegisters)
    , m_areLiveTogether(numVirtRegisters, std::vector<bool>(numVirtRegisters, false))
    , m_numTimesUsed(numVirtRegisters, 0)
    , m_registerAllocations(numVirtRegisters, -1)
    {}

  void addLivenessState(const dlang::LivenessManager& manager);

  void allocateRegisters();

  inline int getAllocationFor(unsigned reg) const { return m_registerAllocations[reg] + 1; }
  
 private:
  bool doConflict(unsigned vr1, unsigned vr2);

  unsigned m_numRegisters;
  unsigned m_numVirtRegisters;

  std::vector<std::vector<bool>> m_areLiveTogether;
  std::vector<unsigned> m_numTimesUsed;
  std::vector<int> m_registerAllocations;
};

#endif
