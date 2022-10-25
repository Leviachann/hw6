#include <assert.h>
#include <iostream>
using namespace std;
template <class T> class Vector {
  T *data = nullptr;
  int size = 0;
public:
  Vector(const Vector &other) { other.data; }
	Vector& operator=(const Vector& value) {
		delete[] data;
		size = value.size;
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = value.data[i];
		}
		return *this;
	
  void PushBack(T value) {
    T *temp = new T[size + 1];
    for (int i = 0; i < size; i++) {
      temp[i] = data[i];
    }
    temp[size] = value;
    delete[] data;
    data = temp;
    size++;
    temp = nullptr;
  }
  void PushFront(T value) {
    T *temp = new T[size + 1];
    for (int i = size; i > 0; i--) {
      temp[i] = value[i - 1];
    }
    temp[0] = value;
    delete[] data;
    data = temp;
    size++;
    temp = nullptr;
  };
  void PushByIndex(int index, T value) {
    T *temp = new T[size + 1];
    for (int i = size + 1; i >= index; i--)
      temp[i] = data[i - 1];
    temp[index - 1] = value;
    delete[] data;
    data = temp;
    size++;
    temp = nullptr;
  };
  T PopByIndex(int index) {
    T *temp = new T[size - 1];
    for (int i = 0; i < size; i++) {
      if (i == (index - 1)) {
        for (int j = i; j < (size - 1); j++) {
          temp[j] = data[j + 1];
        }
        break;
      }
    }
    delete[] data;
    data = temp;
    size--;
    temp = nullptr;
  };
  void Print() const {
    for (int i = 0; i < size; i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  }
  T &operator[](int index) {
    assert(0 <= index && index < size && "Index out of range");
    return data[index];
  }
  ~Vector() { delete[] data; }
};
int main() {}
