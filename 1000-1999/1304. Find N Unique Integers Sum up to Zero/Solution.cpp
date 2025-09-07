/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/?envType=daily-question&envId=2025-09-07
 * Created at: 07/09/2025
 */

#include <fbin/leetcode.h>
using namespace std;

class Solution {
 public:
  vector<int> sumZero(int n) {
    vector<int> arr(n);
    vector<int>::iterator start = arr.begin();
    vector<int>::iterator end = arr.end();
    vector<int>::iterator mid = arr.begin() + n / 2;
    iota(start, mid, -n / 2);
    iota(mid, end, (n % 2) ? 0 : 1);
    for (auto& x : arr) cout << x << " ";
    return arr;
  }
};

int main() {
  Solution* s = new Solution();
  s->sumZero(11);
  return 0;
}
