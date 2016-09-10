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
