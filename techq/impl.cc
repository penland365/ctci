#include "techq/header.h"
#include "lib/hash-table.h"
#include <iostream>
#include <cmath>

void array_pairs() {
  int array[7] = {1, 7, 5, 9, 2, 12, 3};
  auto hash_table = new HashTable<int>();
  for(int i = 0;i < 7; ++i) {
    hash_table->put(array[i], array[i]);
  }
  for(int i = 0;i < 7; ++i) {
    auto x = array[i];
    auto y = x + 2;
    auto ptr = hash_table->get(y);
    if(ptr != nullptr) {
      std::cout <<"Found pair (" << x << ", " << y << ")" << std::endl;
    }
  }
  delete hash_table;
}

void unnecessary_work() {
  for(int a = 1; a <= 1000; ++a) {
    for(int b = 1; b <= 1000; ++b) {
      for(int c = 1; c <= 1000; ++c) {
        int a_cubed = pow(a, 3);
        int b_cubed = pow(b, 3);
        int c_cubed = pow(c, 3);
        int d = std::cbrt(a_cubed + b_cubed - c_cubed);
        if(a_cubed + b_cubed == c_cubed + pow(d, 3)) {
          std::cout << "a^3 + b^3 == c^3 + d^3 found, A = " << a << ", B = " << b << ", C = " << c << ", D = " << d << std::endl;
        }
      }
    }
  }
}

void duplicate_work() {
  std::unique_ptr<HashTable<IntPair>> hash_table(new HashTable<IntPair>());
  for(int c = 1;c <= 1000;++c) {
    for(int d = 1;d <= 1000;++d) {
      int key = pow(c, 3) + pow(d, 3);
      auto pair = new IntPair(c, d);
      hash_table->put(key, *pair); 
    }
  }
  std::cout << "Hello" << std::endl;
  for(int a = 1;a <= 1000;++a) {
    for(int b = 1;b <= 1000;++b) {
      int key = pow(a, 3) + pow(b, 3);
      std::cout << "Pre Segmentation fault, key is " << key << std::endl;
      auto value = hash_table->get(key);
      std::cout << "Segmentation fault?" << std::endl;
      if(value != nullptr) {
        auto c = value->x();
        auto d = value->y();
        std::cout << "a^3 + b^3 == c^3 + d^3 found, A = " << a << ", B = " << b << ", C = " << c << ", D = " << d << std::endl;
      } else {
        std::cout << "No value found" << std::endl;
      }
    }
  }
  std::cout << "Completed" << std::endl;
}

IntPair::IntPair(int x, int y) {
  this->x_ = x;
  this->y_ = y;
}

