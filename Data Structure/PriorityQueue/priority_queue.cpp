#include <climits>
#include <iostream>
using namespace std;

class PriorityQueue {
 private:
  int n;
  int capacity;
  int* data;

  int leftChild(int i) { return 2 * i + 1; }
  int rightChild(int i) { return 2 * i + 2; }
  int parent(int i) { return (i - 1) / 2; }

  void siftUp(int i) {
    while (i > 0) {
      int p = parent(i);
      if (data[i] > data[p]) {
        swap(data[i], data[p]);
        i = p;
      } else {
        break;
      }
    }
  }

  void siftDown(int i) {
    while (true) {
      int left = leftChild(i);
      int right = rightChild(i);
      int largest = i;

      if (left < n && data[left] > data[largest]) {
        largest = left;
      }
      if (right < n && data[right] > data[largest]) {
        largest = right;
      }

      if (largest != i) {
        swap(data[i], data[largest]);
        i = largest;
      } else {
        break;
      }
    }
  }

 public:
  PriorityQueue(int cap) : n(0), capacity(cap) { data = new int[cap]; }

  ~PriorityQueue() {
    delete[] data;
    data = nullptr;
    n = capacity = 0;
  }

  int size() const { return n; }

  int top() const {
    if (n == 0) {
      cout << "Empty queue, fail to get top" << endl;
      return INT_MIN;
    }
    return data[0];
  }

  void push(int num) {
    if (n == capacity) {
      cout << "Over capacity" << endl;
      return;
    }
    data[n] = num;
    siftUp(n);
    n++;
  }

  void pop() {
    if (n == 0) {
      cout << "Empty queue, fail to pop" << endl;
      return;
    }
    swap(data[0], data[n - 1]);
    n--;
    siftDown(0);
  }
};
