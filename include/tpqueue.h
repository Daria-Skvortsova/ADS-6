// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[5];
    int first;
    int last;

 public:
  TPQueue() :first(0), last(0) { }
  void push(T x) {
    int j = 0;
    T value = x;
    for (int i = first; i < size; i++) {
      j = last - 1;
      while ((j >= first) && (arr[(j + 1) % size].prior < value.prior)) {
        if ((arr[(j) % size].prior == value.prior)) {
          arr[(j + 1) % size] = value;
          j++;
          break;
        }
        j--;
        arr[(j + 1) % size] = arr[j % size];
      }
      arr[(j + 1) % size] = value;
      last++;
      break;
    }
  }
  T pop() {
    return arr[(first++) % size];
  }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
