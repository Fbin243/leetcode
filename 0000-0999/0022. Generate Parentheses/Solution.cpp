/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/generate-parentheses/description/
 * Created at: 25/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void generate(vector<string>& res, stack<char>& st, int open, string s, int k,
                int n) {
    if (k == 2 * n) {
      res.push_back(s);
      return;
    }

    char parentheses[2] = {'(', ')'};
    for (int i = 0; i < 2; i++) {
      if (parentheses[i] == '(' && (open < n)) {
        st.push(parentheses[i]);
        generate(res, st, open + 1, s + '(', k + 1, n);
        st.pop();
      } else if (parentheses[i] == ')' && !st.empty() && st.top() == '(') {
        st.pop();
        generate(res, st, open, s + ')', k + 1, n);
        st.push('(');
      }
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> res;
    stack<char> st;

    generate(res, st, 0, "", 0, n);
    return res;
  }
};