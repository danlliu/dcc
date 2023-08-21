
#include <iostream>

extern "C" int dlang_start();

int main() {
  int result = dlang_start();
  std::cout << "dlang returned " << result << std::endl;
}
