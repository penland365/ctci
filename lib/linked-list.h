#ifndef LIB_LINKED_LIST_H_
#define LIB_LINKED_LIST_H_

#include <iostream>

template <class E> class Node {
  public:
    Node(E data) : data_(data) {next = nullptr;};
    ~Node();
    std::shared_ptr<Node<E>> next;
    E data() { return data_; }
  private:
    E data_ {};
};

template <class E>
Node<E>::~Node() {
  next.reset();
}

template <class E> class LinkedList {
  private:
    std::shared_ptr<Node<E>> head;
    std::shared_ptr<Node<E>> tail;
    int recursive_size_(std::shared_ptr<Node<E>> &current_head, int count);
    template<typename Func>
    E* recursive_find(std::shared_ptr<Node<E>> node, Func func);
  public:
    LinkedList();
    LinkedList(E data);
    ~LinkedList();
    void prepend(const E &data);
    void append(E data);
    template<typename Func>
    E* Find(Func func);
    int Size();
    void Delete(const E data_to_delete);
    E Head();   // returns the first element of this list
};

template <class E>
LinkedList<E>::LinkedList() {
  head.reset();
  tail.reset();
}

template <class E>
LinkedList<E>::LinkedList(E data) {
  std::shared_ptr<Node<E>> ptr(new Node<E>(data));
  head = ptr;
  tail = ptr;
}

template <class E>
LinkedList<E>::~LinkedList() {
  head.reset();
  tail.reset();
}

template <class E>
inline int LinkedList<E>::recursive_size_(std::shared_ptr<Node<E>> &current_head, int count) {
  if(current_head->next == nullptr) return count;
  return recursive_size_(current_head->next, ++count);
}

template <class E>
int LinkedList<E>::Size() {
  if(head == nullptr) return 0;
  return recursive_size_(head, 1);
}

template <class E>
void LinkedList<E>::prepend(const E &data) {
  std::shared_ptr<Node<E>> new_head(new Node<E>(data));
  if(head == nullptr && tail == nullptr) {
    head = new_head;
    tail = new_head;
  } else {
    new_head->next = head;
    head = new_head;
  }
}

template <class E>
void LinkedList<E>::append(E data) {
  if(head == nullptr) {
    prepend(data);
  } else {
    std::shared_ptr<Node<E>> tail(new Node<E>(data));
    std::shared_ptr<Node<E>> next_ptr = head;
    while(next_ptr->next != nullptr) {
      next_ptr = next_ptr->next;
    }
    next_ptr->next = tail;
  }
}

template <class E>
E LinkedList<E>::Head() {
  auto ptr = head;
  head = head->next;
  return ptr->data();
}

template <class E>
void LinkedList<E>::Delete(const E data_to_delete) {
  if(head == nullptr) return;
  auto curr_ptr = head;
  auto prev_ptr = head;
  bool found = false;

  while(curr_ptr->next != nullptr && !found) {
    if(curr_ptr->data() == data_to_delete) {
      found = true;
    } else {
      prev_ptr = curr_ptr;
      curr_ptr = curr_ptr->next;
    }
  }
  if(found) {
    if(curr_ptr == head) {
      head = head->next;
    } else if(curr_ptr == tail) {
      tail = prev_ptr;
    }
    prev_ptr->next = curr_ptr->next;
    curr_ptr.reset();
  }
}

template <class E>
template <typename Func>
E* LinkedList<E>::Find(Func func) {
  if(head == nullptr) return nullptr;
  return recursive_find(head, func);
}

template <class E>
template <typename Func>
E* LinkedList<E>::recursive_find(std::shared_ptr<Node<E>> node, Func func) {
  if(node == nullptr) return nullptr;
  E* value = new E(node->data());
  if(func(*value)) return value;
  return recursive_find(node->next, func);
}

#endif
