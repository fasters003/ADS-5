// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
    static const int kSize = size;
    T arr[kSize];
    int top_index;

 public:
    TStack() {
        top_index = -1;
    }

    void push(const T& item) {
        if (top_index < kSize - 1) {
            arr[++top_index] = item;
        }
    }

    T pop() {
        if (top_index >= 0) {
            return arr[top_index--];
        }
        return T();
    }

    T get() const {
        if (top_index >= 0) {
            return arr[top_index];
        }
        return T();
    }

    bool isEmpty() const {
        return top_index == -1;
    }
};

#endif  // INCLUDE_TSTACK_H_
