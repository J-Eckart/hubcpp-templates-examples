#include <iostream>
#include <mutex>
#include <vector>

int main() {

  std::cout << "----min----"
            << "\n";
  std::cout << std::min<double>(2, 3) << "\n";
  std::cout << std::min(2.0, 3.0) << "\n";
  // std::cout << std::min(1, 2.0) << "\n";
  std::cout << std::min<const char *>("abc", "def") << "\n";
  // std::min(std::mutex {}, std::mutex {});

  std::cout << "----vector----"
            << "\n";
  std::vector<int> v{1, 2, 3};
  v.push_back(4);
  for (const auto e : v) {
    std::cout << e << "\n";
  }
}
