// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <iostream>
template <typename T>
class stack {
 public:
  ~stack() { delete[] ptr;
    ptr = nullptr;
    size = 0;
    capacity = 0;
  }
  stack() {
    ptr = nullptr;
    size = 0;
    capacity = 0;
  }
  stack(stack& a) = delete;
  stack(stack&& a) {
    ptr = a.ptr;
    size = a.size;
    capacity = a.capacity;
    a.ptr = nullptr;
  }
  void push(T&& value) {
    if (size < capacity) {
      ptr[size] = value;
      size++;
    } else {
      T* arr = new T[capacity * 2 + 1];
      for (size_t i = 0; i < size; i++) {
        arr[i] = ptr[i];
      }
      arr[size] = value;
      delete[] ptr;
      ptr = arr;
      size++;
      capacity = capacity * 2 + 1;
    }
  }
  void push(const T& value) {
    if (size < capacity) {
      ptr[size] = value;
      size++;
    } else {
      T* arr = new T[capacity * 2 + 1];
      for (size_t i = 0; i < size; i++) {
        arr[i] = ptr[i];
      }
      arr[size] = value;
      delete[] ptr;
      ptr = arr;
      size++;
      capacity = capacity * 2 + 1;
    }
  }
  void pop() { size--; }
  const T& head() const { return ptr[size - 1]; }

 private:
  T* ptr;
  size_t size;
  size_t capacity;
};

template <typename T>
class Stack {
 public:
  Stack() {
    ptr = nullptr;
    size = 0;
    capacity = 0;
  }
  Stack(Stack& a) = delete;
  Stack(Stack&& a) {
    ptr = a.ptr;
    size = a.size;
    capacity = a.capacity;
    a.ptr = nullptr;
  }
  template <typename... Args>
  void push_emplace(Args&&... value) {
    if (size < capacity) {
      ptr[size] = std::move(T(value...));
      size++;
    } else {
      T* arr = new T[capacity * 2 + 1];
      for (size_t i = 0; i < size; i++) {
        arr[i] = ptr[i];
      }
      arr[size] = std::move(T(value...));
      delete[] ptr;
      ptr = arr;
      size++;
      capacity = capacity * 2 + 1;
    }
  }
  const T& head() const { return ptr[size - 1]; }
  T pop() {
    size--;
    return std::move(ptr[size]);
  }

 private:
  T* ptr;
  size_t size;
  size_t capacity;
};
#endif  // INCLUDE_HEADER_HPP_
