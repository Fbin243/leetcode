#include <bits/stdc++.h>
using namespace std;

int ackermann(int m, int n) {
  if (m == 0) return n + 1;
  if (n == 0) return ackermann(m - 1, 1);
  return ackermann(m - 1, ackermann(m, n - 1));
}

/**
 * m = 0: O(1)
 * m = 1: O(n)
 * m = 2: O(n^2)
 * m = 3: O(2^n)
 * m = 4: O(A(4, n))
 */
int ackermann_stack(int m, int n) {
  stack<int> st;
  st.push(m);
  while (!st.empty()) {
    m = st.top();
    st.pop();
    if (m == 0)
      n = n + 1;
    else if (n == 0) {
      st.push(m - 1);
      n = 1;
    } else {
      st.push(m - 1);
      st.push(m);
      n = n - 1;
    }
  }

  return n;
}

int main() {
  cout << "A(1, 8): " << ackermann(1, 8) << endl;
  cout << "A_stack(1, 8): " << ackermann_stack(1, 8) << endl;
  cout << "A(2, 2): " << ackermann(2, 2) << endl;
  cout << "A_stack(2, 2): " << ackermann_stack(2, 2) << endl;
  cout << "A(2, 0): " << ackermann(2, 0) << endl;
  cout << "A_stack(2, 0): " << ackermann_stack(2, 0) << endl;
  cout << "A(2, 3): " << ackermann(2, 3) << endl;
  cout << "A_stack(2, 3): " << ackermann_stack(2, 3) << endl;
  cout << "A(3, 2): " << ackermann(3, 2) << endl;
  cout << "A_stack(3, 2): " << ackermann_stack(3, 2) << endl;
  // cout << "A(4, 2): " << ackermann(4, 2) << endl;
  cout << "A(4, 0): " << ackermann(4, 0) << endl;
  cout << "A_stack(4, 0): " << ackermann_stack(4, 0) << endl;

  return 0;
}
