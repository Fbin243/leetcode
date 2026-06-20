class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        for(int i = 0; i < words.size(); i++) {
            result += (25 - weightOfString(words[i], weights) % 26) + 'a';
        }
        return result;
    }

    int weightOfString(string s, vector<int>& ws) {
        int result = 0;
        for(int i = 0; i < s.length(); i++) {
            result += ws[s[i] - 'a'];
        }
        return result;
    }
};