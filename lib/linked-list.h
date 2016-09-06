#ifndef LIB_LINKED_LIST_H_
#define LIB_LINKED_LIST_H_

#include <iostream>

template <class T> class Node {
  public:
    Node(T data);
    ~Node();
    std::shared_ptr<Node> next;
  private:
    T data;
};
template <class T>
Node<T>::Node(T data) {
  this->data = data;
  next = nullptr;
}

template <class T>
Node<T>::~Node() {
  next.reset();
}

template <class T> class LinkedList {
  private:
    std::shared_ptr<Node<T>> head;
  public:
    LinkedList();
    LinkedList(T data);
    ~LinkedList();
    void prepend(T data);
    void append(T data);
    int Size();
};

template <class T>
LinkedList<T>::LinkedList() {
  head.reset();
}

template <class T>
LinkedList<T>::LinkedList(T data) {
  std::shared_ptr<Node<T>> ptr(new Node<T>(data));
  head = ptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
  head.reset();
}

template <class T>
int LinkedList<T>::Size() {
  if(head == nullptr) return -1;
  std::shared_ptr<Node<T>> next_ptr = head;
  int count = 0;
  while(next_ptr != nullptr) {
    next_ptr = next_ptr->next;
    ++count;
  }
  return count;
}

template <class T>
void LinkedList<T>::prepend(T data) {
  std::shared_ptr<Node<T>> new_head(new Node<T>(data));
  new_head->next = head;
  head = new_head;
}

template <class T>
void LinkedList<T>::append(T data) {
  if(head == nullptr) prepend(data);  
  std::shared_ptr<Node<T>> tail(new Node<T>(data));
  std::shared_ptr<Node<T>> next_ptr = head;
  while(next_ptr->next != nullptr) {
    next_ptr = next_ptr->next;
  }
  next_ptr->next = tail;
}
#endif
