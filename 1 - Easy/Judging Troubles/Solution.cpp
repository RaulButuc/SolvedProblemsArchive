#include <map>
#include <vector>
#include <string>
#include <limits>
#include <iostream>

auto main(int argc, char *argv[]) -> int {
  std::map<std::string, int> dom;
  std::map<std::string, int> kat;
  std::string w;
  int t, r = 0;

  std::cin >> t;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  for (auto i = 0; i < t; ++i) {
    std::getline(std::cin, w);
    dom[w]++;
  }

  for (auto i = 0; i < t; ++i) {
    std::getline(std::cin, w);
    kat[w]++;
  }

  for (auto it = dom.begin(); it != dom.end();
       ++it) {
    r += std::min(it->second, kat[it->first]);
  }

  std::cout << r;

  return 0;
}
