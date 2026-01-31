/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/?envType=daily-question&envId=2026-01-31
 * Created at: 31/01/2026
 */

#include <fbin/leetcode.h>

class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    char smallestGreater = 'z' + 1;
    for (int i = 0; i < letters.size(); i++) {
      if (letters[i] > target && smallestGreater > letters[i]) {
        smallestGreater = letters[i];
      }
    }
    return smallestGreater == 'z' + 1 ? letters[0] : smallestGreater;
  }
};
