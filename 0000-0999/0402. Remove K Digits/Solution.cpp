/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/remove-k-digits/description/?envType=problem-list-v2&envId=monotonic-stack
 * Created at: 29/03/2025
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string removeKdigits(string num, int k) {
    stack<char> s;
    for (int i = 0; i < num.length(); i++) {
      while (!s.empty() && s.top() > num[i] && k > 0) {
        s.pop();
        k--;
      }
      if (s.empty() && num[i] == '0') continue;
      s.push(num[i]);
    }

    string res = "";
    while (!s.empty()) {
      char top = s.top();
      s.pop();
      if (k > 0) {
        k--;
        continue;
      }
      res.push_back(top);
    }
    reverse(res.begin(), res.end());

    if (res == "") res = "0";
    return res;
  }
};

int main() {
  Solution* sol = new Solution();
  string num = "1234";
  int k = 4;
  cout << sol->removeKdigits(num, k);

  return 0;
}