class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string res = "";
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) res += " ";
            res += words[i];
        }

        return res;
    }
};