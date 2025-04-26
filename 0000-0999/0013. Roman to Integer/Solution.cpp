/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/roman-to-integer/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 26/04/2025
 */

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, int> m = {
        {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000},
    };
    int n = s.length();
    int res = 0;

    for (int i = 0; i < n; i++) {
      if (i != n - 1 && m[s[i]] < m[s[i + 1]]) {
        res += m[s[i + 1]] - m[s[i]];
        i++;
      } else {
        res += m[s[i]];
      }
    }

    return res;
  }
};