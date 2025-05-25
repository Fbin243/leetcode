/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 * Created at: 25/05/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int eval(int num1, int num2, char op) {
    switch (op) {
      case '*':
        return num1 * num2;
      case '/':
        return num1 / num2;
      case '+':
        return num1 + num2;
      default:
        return num1 - num2;
    }
  }

  int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for (int i = 0; i < tokens.size(); i++) {
      int len = tokens[i].length();
      int isNegative = false;
      if (isdigit(tokens[i][len - 1])) {
        int num = 0;
        for (int j = 0; j < len; j++) {
          if (j == 0 && !isdigit(tokens[i][j]))
            isNegative = true;
          else
            num = num * 10 + (tokens[i][j] - '0');
        }
        st.push(isNegative ? -num : num);
      } else {
        int num2 = st.top();
        st.pop();
        int num1 = st.top();
        st.pop();
        st.push(eval(num1, num2, tokens[i][0]));
      }
    }

    return st.top();
  }
};