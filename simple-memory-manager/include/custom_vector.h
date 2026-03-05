#ifndef CUSTOM_VECTOR_H

#define CUSTOM_VECTOR_H

#include <iostream>
template <typename T> // templates are blueprints for classes
class CustomVector {
private:
  T *data;
  int v_size;
  int v_capacity;

public:
  CustomVector(int capacity) {
    data = new T[capacity];
    v_size = 0;
    v_capacity = capacity;
  }

  CustomVector(const CustomVector<T> &other)
      : data(new T[other.v_capacity]), v_size(other.v_size),
        v_capacity(other.v_capacity) {
    for (int i = 0; i < v_size; i++)
      data[i] = other.data[i];
  }

  ~CustomVector() { delete[] data; }
  CustomVector<T> &operator=(const CustomVector<T> &other) {
    if (this == &other) {
      return *this;
    }

    delete[] data;
    v_capacity = other.v_capacity;
    v_size = other.v_size;
    data = new T[v_capacity];
    for (int i = 0; i < v_size; i++) {
      data[i] = other.at(i);
    }

    return *this;
  }
  void push_back(T value) {
    if (v_size == v_capacity) {
      int new_capacity = v_capacity * 2;
      T *new_data = new T[new_capacity];
      for (int i = 0; i < v_size; i++) {
        new_data[i] = data[i];
      }

      delete[] data;
      data = new_data;
      v_capacity = new_capacity;
    }

    data[v_size] = value;
    v_size++;
  };
  void set(T val, int index) {
    if (index >= v_size) {
      std::cout << "Out of bounds index" << std::endl;
      return;
    }

    data[index] = val;
    return;
  }

  T &at(int index) const {
    if (index >= v_size) {
      std::cout << "Error out of bounds of vector" << std::endl;
    }
    return data[index];
  }

  int size() { return v_size; }

  int capacity() { return v_capacity; }
};

#endif
