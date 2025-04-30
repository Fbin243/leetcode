/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 30/04/2025
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    set<int> seen;
    while (n != 1) {
      int sqSum = 0;
      while (n > 0) {
        sqSum += pow(n % 10, 2);
        n /= 10;
      }
      n = sqSum;
      if (seen.find(n) != seen.end()) return false;
      seen.insert(n);
    }

    return true;
  }
};
