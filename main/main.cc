#include <iostream>
#include <string>
#include "lib/linked-list.h"

int main(int argc, char** argv) {
  std::unique_ptr<LinkedList<std::string>> strings(new LinkedList<std::string>("Hello"));
  strings->prepend("Jeff");
  strings->append("Davis");
  int num_strings = strings->Size();
        //"@gtest//:main",

  std::cout << "There were " << num_strings << " total strings" << std::endl;
  strings.reset(nullptr);
  return 0;
}
