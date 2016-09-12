#ifndef TECHQ_HEADER_H_ 
#define TECHQ_HEADER_H_ 

#include <string>

void array_pairs();
void unnecessary_work();
void duplicate_work();

class IntPair {
  public:
    IntPair(int x, int y);
    int x() { return x_; };
    int y() { return y_; };
  private:
    int x_;
    int y_;
};

#endif
