/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/decode-string/description/?envType=problem-list-v2&envId=stack
 * Created at: 17/03/2025
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string decodeString(string s) {
    stack<string> st;
    s += '0';

    string num = "";
    string alpha = "";
    for (char c : s) {
      if (isdigit(c)) {
        num += c;
        if (alpha != "") {
          st.push(alpha);
          alpha = "";
        }
      }
      if (isalpha(c)) {
        alpha += c;
      }
      if (c == '[') {
        st.push(num);
        num = "";
      }
      if (c == ']') {
        cout << "stack:";
        printStack(st);
        do {
          string topItem = st.top();
          st.pop();
          if (topItem[0] >= '0' && topItem[0] <= '9') {
            int times = stoi(topItem);
            cout << "time: " << times << endl;
            string unit = alpha;
            cout << "unit " << unit << endl;
            alpha = "";
            while (times--) {
              alpha += unit;
            }
            break;
          };
          alpha = topItem + alpha;
        } while (!st.empty());
        st.push(alpha);
        alpha = "";
      }
    }

    string res = "";
    while (!st.empty()) {
      res = st.top() + res;
      st.pop();
    }

    return res;
  }

  template <typename T>
  void printStack(stack<T> s) {
    cout << "{";
    while (!s.empty()) {
      cout << s.top() << ", ";
      s.pop();
    }
    cout << "}\n";
  }
};

int main() {
  Solution* s = new Solution();
  cout << "res: " << s->decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef") << endl;

  return 0;
}