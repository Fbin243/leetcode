/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/?envType=daily-question&envId=2025-09-16
 * Created at: 16/09/2025
 */

#include <fbin/leetcode.h>
class Solution {
 public:
  int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
  }

  int lcm(int a, int b) { return a / gcd(a, b) * b; }

  bool isCoprime(int a, int b) { return gcd(a, b) == 1; }

  vector<int> replaceNonCoprimes(vector<int>& nums) {
    list<int> lnums;
    for (int i = 0; i < nums.size(); i++) {
      lnums.push_back(nums[i]);
    }

    bool beReplaced = true;
    bool odd = false;
    while (beReplaced) {
      beReplaced = false;
      odd = !odd;
      if (odd) {
        for (auto it = lnums.begin(); it != prev(lnums.end());) {
          auto nextIt = next(it);
          if (!isCoprime(*it, *nextIt)) {
            *it = lcm(*it, *nextIt);
            lnums.erase(nextIt);
            beReplaced = true;
          } else
            it = next(it);
        }
      } else {
        for (auto it = prev(lnums.end()); it != lnums.begin();) {
          auto prevIt = prev(it);
          if (!isCoprime(*it, *prevIt)) {
            *it = lcm(*it, *prevIt);
            lnums.erase(prevIt);
            beReplaced = true;
          } else
            it = prev(it);
        }
      }
    }

    vector<int> res;
    for (auto& x : lnums) {
      res.push_back(x);
    }

    return res;
  }
};

int main() {
  Solution* s = new Solution();
  vector<int> v = {2, 3, 2, 3, 2, 3, 6, 6};
  vector<int> res = s->replaceNonCoprimes(v);
  for (int i = 0; i < res.size(); i++) cout << res[i] << ", ";
  return 0;
}

/*
[6,4,3,2,7,6,2]
[12,3,2,7,6,2]
[12,7,6]

[2,2,1,1,3,3,3]
[2,1,1,3,3,3]
[2,1,1,3]

1. How to know if two values are non coprime?
- Coprime: GCD(a, b) = 1
- Non Coprime: GCD(a, b) > 1
=> Write GCD func to check and used it in IsCoprime()

2. How to find adjacent non coprime values?
- Call IsCoprime() for each pair of adjacent values in array? -> O(N)

3. How to replace them with their LCM ?
- If two adjacent non coprime values found, use the formula
        LCM(a, b) = |a * b| / GCD(a, b)
        Then replace LCM by make a new array ? -> O(N)
- Can optimize by using LinkedList -> O(1)

Brute Force: O(N^2)

Linked List: O(N)
- Worst case: Each time reduce the number of items by 1 -> O(N^2)

4, 2 -> 2, 0
*/
