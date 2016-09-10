#include "techq/header.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  std::string who = "Jeff";
  std::cout << get_greet(who) << std::endl;
  return 0;
}
