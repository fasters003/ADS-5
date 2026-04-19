// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
  T* data;
  int top_index;

 public:
  TStack() : top_index(-1) {
    data = new T[size];
  }

  ~TStack() {
    delete[] data;
  }

  bool isEmpty() const {
    return top_index == -1;
  }

  bool isFull() const {
    return top_index == size - 1;
  }

  void push(T value) {
    if (!isFull()) {
      data[++top_index] = value;
    }
  }

  T pop() {
    if (!isEmpty()) {
      return data[top_index--];
    }
    return T();
  }

  T top() const {
    if (!isEmpty()) {
      return data[top_index];
    }
    return T();
  }

  void clear() {
    top_index = -1;
  }

  int getSize() const {
    return top_index + 1;
  }
};

#endif  // INCLUDE_TSTACK_H_
