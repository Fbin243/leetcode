/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/integer-to-roman/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 26/04/2025
 */

#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string digitToRoman(int digit, int level) {
    vector<pair<int, char>> v = {{1, 'I'},   {5, 'V'},   {10, 'X'},  {50, 'L'},
                                 {100, 'C'}, {500, 'D'}, {1000, 'M'}};
    int n = v.size() - 1;
    int power = pow(10, level);
    int value = digit * power;
    string res = "";

    if (digit != 4 && digit != 9) {
      while (value > 0) {
        if (value >= v[n].first) {
          value -= v[n].first;
          res += v[n].second;
        } else
          n--;
      }
    } else {
      for (int i = 0; i <= n; i++) {
        if (v[i].first == power || v[i].first == value + power)
          res += v[i].second;
      }
    }

    return res;
  }

  string intToRoman(int num) {
    string res = "";
    int level = 0;

    while (num > 0) {
      int digit = num % 10;
      res = digitToRoman(digit, level) + res;
      num = num / 10;
      level++;
    }

    return res;
  }
};