#include <iostream>
#include "Optional.hpp"

Optional<int> test(bool stat) {
  if(stat)
    return Optional<int>(1);
  else
    return Nullopt::nullopt;
}

int main() {

  Optional<int> opt = {1};

  std::cout << (opt == test(false)) << '\n';

  std::cout << opt.get() << '\n';
}
