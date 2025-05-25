/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/min-stack/?envType=problem-list-v2&envId=stack
 * Created at: 15/03/2025
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Approach: Use two stacks to implement MinStack
 * I use array to store the value of stack and a int variable to store the top
 * pointer. Beside that, I also use another array to keep track the indices of
 * min values in stack.
 *
 * Time complexity: O(1)
 * Space complexity: O(n)
 */

class MinStack1 {
  int min_arr[30000];
  int top_min_idx;
  int arr[30000];
  int top_idx;

 public:
  MinStack1() {
    top_idx = -1;
    top_min_idx = -1;
  }

  void push(int val) {
    arr[++top_idx] = val;
    if (top_min_idx == -1) {
      min_arr[++top_min_idx] = top_idx;
    } else if (arr[min_arr[top_min_idx]] > arr[top_idx]) {
      min_arr[++top_min_idx] = top_idx;
    }
  }

  void pop() {
    if (top_idx == -1) return;
    if (top_idx == min_arr[top_min_idx]) {
      top_min_idx--;
    }
    top_idx--;
  }

  int top() {
    if (top_idx == -1) return INT32_MIN;
    return arr[top_idx];
  }

  int getMin() {
    if (top_min_idx == -1) return INT32_MIN;
    return arr[min_arr[top_min_idx]];
  }
};

/**
 * Solution at 25/05/2025
 */
class MinStack {
 private:
  stack<int> st;
  stack<int> minSt;

 public:
  MinStack() {}

  void push(int val) {
    if (minSt.empty() || (minSt.top() >= val)) minSt.push(val);
    st.push(val);
  }

  void pop() {
    if (!minSt.empty() && (minSt.top() == st.top())) minSt.pop();
    st.pop();
  }

  int top() { return st.top(); }

  int getMin() { return minSt.top(); }
};

int main() {
  MinStack1* minSt = new MinStack1();
  minSt->push(-2);
  minSt->push(0);
  minSt->push(-3);
  cout << "Min: " << minSt->getMin() << endl;
  minSt->pop();
  cout << "Top: " << minSt->top() << endl;
  cout << "Min: " << minSt->getMin() << endl;
  return 0;
}