#include <deque>
#include <iostream>
using namespace std;

void printDeque(deque<int>& dq) {
  for (auto x : dq) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  // Initialize deque: O(n)
  deque<int> dq = {1, 4, 2, 3, 5};
  deque<int> dq1(5, 3);
  deque<int> dq2{1, 2, 3, 4, 5};

  // Get size of the deque: O(1)
  cout << dq.size() << endl;

  // Check if a deque is empty: O(1)
  cout << dq.empty() << endl;

  // Insert at back and front: O(1)
  dq.push_back(6);
  dq.push_front(0);

  // Insert at a random index: O(1)
  dq.insert(dq.begin() + 1, -1);

  // Randomly access with operator[]: O(1)
  cout << dq[2] << endl;

  // Randomly access with bound checking: O(1)
  cout << dq.at(2) << endl;

  // Access the first and last element: O(1)
  cout << dq.front() << endl;
  cout << dq.back() << endl;

  // Updating element with operator[]: O(1)
  dq[1] = -2;

  // Traversing: O(n)
  for (int i = 0; i < dq.size(); i++) cout << dq[i] << " ";
  cout << endl;

  // Deleting elements from front and back: O(1)
  dq.pop_front();
  dq.pop_back();

  // Deleting element from random index: O(1)
  dq.erase(dq.end() - 2);

  printDeque(dq);

  return 0;
}