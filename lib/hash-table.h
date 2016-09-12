#ifndef LIB_HASH_TABLE_H_
#define LIB_HASH_TABLE_H_

#include "lib/linked-list.h"

template <class E> class HashEntry {
  public:
    HashEntry(int key, E value) : value_(value) {key_ = key;};
    int key() { return key_; };
    E value() { return value_; };
  private:
    int key_;
    E value_ {};
};

template <class E> class HashTable {
  public:
    HashTable<E>();
    ~HashTable<E>();
    int size() { return size_; };
    void put(const int key, const E value);
    E* get(const int key);
  private:
    std::unique_ptr<std::unique_ptr<LinkedList<HashEntry<E>>>[]> array_;
    int size_;
    int array_length_;
    void initialize_array_(int size);
};

template <class E>
void HashTable<E>::initialize_array_(int size) {
  for(int i = 0;i < size;++i) {
    std::unique_ptr<LinkedList<HashEntry<E>>> tmp(new LinkedList<HashEntry<E>>);
    array_[i] = std::move(tmp);
  }
}

template <class E>
HashTable<E>::HashTable() {
  size_ = 0;
  array_length_ = 128;
  std::unique_ptr<std::unique_ptr<LinkedList<HashEntry<E>>>[]> array_temp(new std::unique_ptr<LinkedList<HashEntry<E>>>[array_length_]);
  array_ = std::move(array_temp);
  array_temp.reset();
  initialize_array_(array_length_);
}

template <class E>
HashTable<E>::~HashTable() {
  for(int i = 0;i < array_length_;++i) {
    auto j = std::move(array_[i]);
    j.reset();
  }
  array_.reset();
}

template <class E>
void HashTable<E>::put(int key, E value) {
  int idx = key % array_length_;
  auto list = std::move(array_[idx]);
  std::unique_ptr<HashEntry<E>> new_entry(new HashEntry<E>(key, value));
  auto entry = new HashEntry<E>(key, value);
  list->prepend(*entry);
  array_[idx] = std::move(list);
}

template <class E>
E* HashTable<E>::get(const int key) {
  int idx = key % array_length_;
  std::cout << "idx is " << idx << std::endl;
  auto list = std::move(array_[idx]);
  auto* hash_entry = list->Find(
    [&key] (HashEntry<E>& entry) -> bool { return entry.key() == key; }
  );
  array_[idx] = std::move(list);
  return hash_entry == nullptr ? nullptr : new E(hash_entry->value());
}

#endif
