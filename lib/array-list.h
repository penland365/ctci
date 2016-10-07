#ifndef LIB_ARRAY_LIST_H_
#define LIB_ARRAY_LIST_H_

#include <stdexcept>

template <class E> class ArrayList {
  public:
    ArrayList();
    ~ArrayList();
    E& operator[](const int idx);
    E foo();
  private:
    long kInitialSize = 64;
    E *array_;
    long array_size_;
    long curr_size_;
};

template<class E>
ArrayList<E>::ArrayList() {
  array_size_ = kInitialSize;
  curr_size_ = 0;
  array_ = new E[array_size_];
}

template<class E>
ArrayList<E>::~ArrayList() {
  delete[] array_;
}

template<class E>
E& ArrayList<E>::operator[](const int idx) {
  if(idx < 0 || idx > curr_size_) throw std::out_of_range("Out of range my man");
  return array_[idx];
}


template<class E>
E ArrayList<E>::foo() {
  return this[0];
}

//template<class E>
//E& ArrayList<E>::operator=(const E& other) {
//      
//  return *this;
//}

#endif
