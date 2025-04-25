/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/valid-parentheses/description/?envType=problem-list-v2&envId=stack
 * Created at: 11/03/2025
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Approach: Stack
 *
 * We use a stack to validate the order of parentheses efficiently.
 * The Last-In-First-Out (LIFO) property of a stack ensures that each
 * opening bracket is matched with the correct closing bracket in order.
 *
 * Time Complexity: O(n) – We traverse the string once.
 * Space Complexity: O(n) – In the worst case, all characters are stored in the
 * stack.
 */

bool checkPair(char c1, char c2) {
  if (c1 == ')') return c2 == '(';
  if (c1 == ']') return c2 == '[';
  if (c1 == '}') return c2 == '{';
  return false;
}

bool isValid(string s) {
  stack<char> st;
  for (char c : s) {
    if (c == ')' || c == ']' || c == '}') {
      if (st.empty()) return false;
      if (!checkPair(c, st.top())) return false;
      st.pop();
    } else {
      st.push(c);
    }
  }

  return st.empty();
}

int main() {
  cout << "Result: " << isValid("{}[]()");
  return 0;
}