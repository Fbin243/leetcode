/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/vowel-spellchecker/?envType=daily-question&envId=2025-09-15
 * Created at: 15/09/2025
 */

#include <fbin/leetcode.h>

class Solution {
 public:
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

  string toLowercase(string s) {
    string res = "";
    for (int i = 0; i < s.size(); i++) {
      res += tolower(s[i]);
    }
    return res;
  }

  string standardizeVowel(string s) {
    string res = "";
    for (int i = 0; i < s.size(); i++) {
      if (isVowel(s[i])) {
        res += '#';
      } else {
        res += s[i];
      }
    }
    return res;
  }

  vector<string> spellchecker(vector<string>& wordlist,
                              vector<string>& queries) {
    unordered_set<string> wordSet;
    unordered_map<string, string> capitalizationSet;
    unordered_map<string, string> standardizeSet;
    for (int i = 0; i < wordlist.size(); i++) {
      wordSet.insert(wordlist[i]);
			string lowercaseWord = toLowercase(wordlist[i]);
			if(capitalizationSet.find(lowercaseWord) == capitalizationSet.end()) {
				capitalizationSet[lowercaseWord] = wordlist[i];
			}
			string standardizeWord = standardizeVowel(lowercaseWord);
			if(standardizeSet.find(standardizeWord) == standardizeSet.end()) {
				standardizeSet[standardizeWord] = wordlist[i];
			}
    }
    for (int i = 0; i < queries.size(); i++) {
      // 1. Exactly match
      if (wordSet.find(queries[i]) != wordSet.end()) continue;

      // 2. Capitalization
      string lowercaseWord = toLowercase(queries[i]);
      if (capitalizationSet.find(lowercaseWord) != capitalizationSet.end()) {
        queries[i] = capitalizationSet[lowercaseWord];
				continue;
      }

      // 3. Vowel Err
      string standardizedWord = standardizeVowel(lowercaseWord);
      if (standardizeSet.find(standardizedWord) != standardizeSet.end()) {
        queries[i] = standardizeSet[standardizedWord];
				continue;
      }

			// 4. No matches
			queries[i] = "";
    }

    return queries;
  }
};

int main() {
	Solution *s = new Solution();
	cout << s->toLowercase("NguyEn ThaNh BiNh");
	return 0;
}
