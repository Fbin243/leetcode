/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/remove-duplicate-letters/?envType=problem-list-v2&envId=stack
 * Created at: 22/03/2025
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string removeDuplicateLetters(string s) {
    int a[26] = {0};
    int visited[26] = {0};
    stack<char> st;
    string res = "";
    for (char c : s) {
      a[c - 'a']++;
    }
    for (char c : s) {
      a[c - 'a']--;
      if (!visited[c - 'a']) {
        while (!st.empty() && st.top() > c && a[st.top() - 'a'] > 0) {
          visited[st.top() - 'a'] = 0;
          st.pop();
        }
        st.push(c);
        visited[c - 'a'] = 1;
      }
    }

    string str = "";
    while (!st.empty()) {
      char top = st.top();
      st.pop();
      str = top + str;
    }

    return str;
  }
};

int main() {
  Solution* sol = new Solution();
  string s = "cbacdcbc";
  cout << sol->removeDuplicateLetters(s);

  return 0;
}
