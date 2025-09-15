/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/?envType=daily-question&envId=2025-09-15
 * Created at: 15/09/2025
 */

#include <fbin/leetcode.h>
using namespace std;

class Solution {
 public:
  int canBeTypedWords(string text, string brokenLetters) {
    unordered_set<char> brokenSet;
    for (int i = 0; i < brokenLetters.size(); i++) {
      brokenSet.insert(brokenLetters[i]);
    }
    bool isBroken = false;
    int typedWords = 0;
    for (int i = 0; i < text.size(); i++) {
      if (brokenSet.find(text[i]) != brokenSet.end()) {
        isBroken = true;
      }
      if ((text[i] == ' ' || i == text.size() - 1)) {
        if (!isBroken) typedWords++;
        isBroken = false;
      }
    }
    return typedWords;
  }
};
