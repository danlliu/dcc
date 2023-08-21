
#include "register_allocator.h"

#include <numeric>
#include <queue>

#include "compiler_context.h"

void RegisterAllocator::addLivenessState(dlang::LivenessManager const& manager) {
  for (unsigned i = 0; i < m_numVirtRegisters; ++i) {
    if (manager.isLive(i)) {
      ++m_numTimesUsed[i];
      for (unsigned j = 0; j < i; ++j) {
        m_areLiveTogether[i][j] = m_areLiveTogether[i][j] || (manager.isLive(i) && manager.isLive(j));
      }
    }
  }
}

void RegisterAllocator::allocateRegisters() {
  std::vector<std::vector<unsigned>> neighbors(m_numVirtRegisters);
  for (unsigned i = 0; i < m_numVirtRegisters; ++i) {
    for (unsigned j = 0; j < i; ++j) {
      if (doConflict(i, j)) {
        neighbors[i].push_back(j);
        neighbors[j].push_back(i);
      }
    }
  }

  // Go in order of most used to least used
  auto Comparator = [&](unsigned lhs, unsigned rhs) { return m_numTimesUsed[lhs] < m_numTimesUsed[rhs]; };
  std::vector<unsigned> virtRegs(m_numVirtRegisters);
  std::iota(begin(virtRegs), end(virtRegs), 0);
  std::priority_queue<unsigned, std::vector<unsigned>, decltype(Comparator)> pq(begin(virtRegs), end(virtRegs),
                                                                                Comparator);
  while (size(pq)) {
    auto next = pq.top();
    pq.pop();
    std::vector<bool> used(m_numVirtRegisters, false);
    for (auto n : neighbors[next]) {
      if (m_registerAllocations[n] != -1) used[static_cast<unsigned>(m_registerAllocations[n])] = true;
    }
    // find first available color
    for (unsigned c = 0; c < m_numRegisters; ++c) {
      if (!used[c]) {
        m_registerAllocations[next] = static_cast<int>(c);
        break;
      }
    }
  }
}

bool RegisterAllocator::doConflict(unsigned vr1, unsigned vr2) {
  return m_areLiveTogether[vr1][vr2] || m_areLiveTogether[vr2][vr1];
}
