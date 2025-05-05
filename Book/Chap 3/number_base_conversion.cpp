#include <iostream>
#include <stack>
using namespace std;

// Convert decimal to base k
int convert_number_base(int n, int k) {
  stack<int> st;
  while (n != 0) {
    st.push(n % k);
    n = n / k;
  }

  while (!st.empty()) {
    n = n * 10 + st.top();
    st.pop();
  }

  return n;
}

int main() {
  int n = 2025;
  int k = 8;
  cout << n << " in decimal to base " << k
       << " is: " << convert_number_base(n, k) << endl;
  return 0;
}
