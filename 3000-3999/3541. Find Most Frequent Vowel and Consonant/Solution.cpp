/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/?envType=daily-question&envId=2025-09-15
 * Created at: 15/09/2025
 */

#include <fbin/leetcode.h>

class Solution {
 public:
	bool isVowel(char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}

  int maxFreqSum(string s) {
    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); i++) {
      freq[s[i] - 'a']++;
    }
    int vowelFreq = 0;
    int consonantFreq = 0;
    for (int i = 0; i < 26; i++) {
			if(isVowel(i + 'a') && freq[i] > vowelFreq) vowelFreq = freq[i];
			if(!isVowel(i + 'a') && freq[i] > consonantFreq) consonantFreq = freq[i];
    }
    return vowelFreq + consonantFreq;
  }
};

int main() {
  Solution *s = new Solution();
  cout << s->maxFreqSum("abca");
  return 0;
}
