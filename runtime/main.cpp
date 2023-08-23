
#include <iostream>

extern "C" int dlang_main();

int main() {
  int result = dlang_main();
  std::cout << "dlang returned " << result << std::endl;
}
