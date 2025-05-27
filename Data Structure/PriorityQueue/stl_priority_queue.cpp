#include <bits/stdc++.h>
using namespace std;

void print(priority_queue<int> pq) {
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl;
}

int main() {
  // Create an empty priority queue
  priority_queue<int> pq;

  // Add elements to queue and get top
  pq.push(9);
  pq.push(10);
  pq.push(6);

  cout << pq.top() << endl;

  // Init a queue from other container
  vector<int> v = {9, 10, 8, 6};
  priority_queue<int> pq2;
  pq2 = {v.begin(), v.end()};
  print(pq2);

  // Delete elements
  pq.pop();
  print(pq);

  // Changing to min-heap
  priority_queue<int, vector<int>, greater<int>> pq4;
  pq4.push(5);
  pq4.push(6);
  pq4.push(4);
  pq4.push(10);

  // Traverse queue
  while (!pq4.empty()) {
    cout << pq4.top() << " ";
    pq4.pop();
  }
  cout << endl;

  return 0;
}
