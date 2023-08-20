
#ifndef _DCC_LABEL_MANAGER_H
#define _DCC_LABEL_MANAGER_H

namespace dlang {
  class LabelManager {
   public:
    LabelManager() {}

    inline static unsigned nextLabel() { return nextID++; }
   private:
    static unsigned nextID;
  };
}

#endif
