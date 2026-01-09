/**
 * Author: Fbin
 * Created at: 24/03/2025
 * Link:https://leetcode.com/problems/count-largest-group/description/?envType=daily-question&envId=2025-04-23
 * Goal: Zalopay Tech Freshers 2025
 */

#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }

  return sum;
}

class Solution {
 public:
  int countLargestGroup(int n) {
    unordered_map<int, int> map;
    int maxSize = 0;
    for (int i = 1; i <= n; i++) {
      maxSize = max(maxSize, ++map[sumOfDigits(i)]);
    }

    int res = 0;
    for (const auto& it : map) {
      if (it.second == maxSize) {
        res++;
      }
    }

    return res;
  }
};
