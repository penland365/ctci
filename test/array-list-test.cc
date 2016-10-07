#include "gtest/gtest.h"
#include "lib/array-list.h"

TEST(ArrayList, NilList) {
  auto array = new ArrayList<int>();
  int f = array->foo(); 
  //array[0] = 71;
  std::cout << "F is " << f << std::endl;
  ASSERT_EQ(71, 71) << "Nil LinkedList should have zero size";
}

