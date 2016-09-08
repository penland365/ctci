#include "gtest/gtest.h"
#include "lib/linked-list.h"

TEST(LinkedListTest, NilList) {
  std::unique_ptr<LinkedList<int>> list(new LinkedList<int>());
  ASSERT_EQ(list->Size(), 0) << "Nil LinkedList should have zero size";
}

TEST(LinkedListTest, OneElementList) {
  std::unique_ptr<LinkedList<int>> list(new LinkedList<int>(71));
  ASSERT_EQ(list->Size(), 1) << "Initial LinkedList should have one element.";
}

TEST(LinkedListTest, Head) {
  std::unique_ptr<LinkedList<int>> list(new LinkedList<int>(71));
  list->prepend(17);
  auto head = list->Head();
  ASSERT_EQ(head, 17) << "Initial LinkedList should have one element.";
}

TEST(LinkedListTest, Delete) {
  std::unique_ptr<LinkedList<int>> list(new LinkedList<int>(1));
  list->append(2);
  list->append(3);
  list->Delete(1);
  auto head = list->Head();
  auto second_head = list->Head();
  ASSERT_EQ(second_head, 3) << "Delete Element did not work";
}
