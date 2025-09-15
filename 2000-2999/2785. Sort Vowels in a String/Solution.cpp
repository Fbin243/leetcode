/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/sort-vowels-in-a-string/?envType=daily-question&envId=2025-09-11
 * Created at: 11/09/2025
 */

#include <fbin/leetcode.h>
using namespace std;

class Solution {
 public:
  static bool isVowel(char c) {
    return c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' ||
           c == 'i' || c == 'U' || c == 'u' || c == 'O' || c == 'o';
  }

  string sortVowels(string s) {
    vector<int> idx(s.size());
    vector<char> vowels;
    for (int i = 0; i < s.size(); i++) {
      if (isVowel(s[i])) vowels.push_back(s[i]);
    }

    sort(vowels.begin(), vowels.end(), [](char a, char b) { return b > a; });

    int k = 0;
    for (int i = 0; i < s.size(); i++) {
      if (isVowel(s[i])) s[i] = vowels[k++];
    }

    // --- Not work ---
    // iota(idx.begin(), idx.end(), 0);
    // sort(idx.begin(), idx.end(), [&](int i, int j) {
    //   cout << "Idx: " << i << ", " << j << endl;
    //   cout << "Compare: " << s[i] << ", " << s[j] << endl;
    //   if (isVowel(s[i]) && isVowel(s[j]) && s[i] != s[j]) return s[i] < s[j];
    //   return i < j;
    // });

    return s;
  }
};

int main() {
  Solution *s = new Solution();
  string str = "lEetcOde";
  cout << s->sortVowels(str);
  return 0;
}
