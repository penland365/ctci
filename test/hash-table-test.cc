#include "gtest/gtest.h"
#include "lib/hash-table.h"
#include <string>

TEST(HashEntryTest, KeyTest) {
  std::unique_ptr<HashEntry<int>> entry(new HashEntry<int>(71, 7171));
  ASSERT_EQ(entry->key(), 71) << "Invalid key returned for Hash Entry";
}

TEST(HashEntryTest, ValueTest) {
  std::unique_ptr<HashEntry<int>> entry(new HashEntry<int>(71, 7171));
  ASSERT_EQ(entry->value(), 7171) << "Invalid value returned for Hash Entry";
}

TEST(HashTableTest, EmptySizeTest) {
  std::unique_ptr<HashTable<std::string>> hash_table(new HashTable<std::string>());
  ASSERT_EQ(hash_table->size(), 0) << "Empty HashTable should have zero size";
}

TEST(HashTableTest, GetAndPutTest) {
  std::unique_ptr<HashTable<std::string>> hash_table(new HashTable<std::string>());
  hash_table->put(71, "hello");
  auto result = hash_table->get(71);
  ASSERT_EQ(*result, "hello");
}
