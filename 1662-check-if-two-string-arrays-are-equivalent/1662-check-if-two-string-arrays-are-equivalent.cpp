class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string res1 = "";
        string res2 = "";

        for (string s : word1) {
            res1 += s;
        }

        for (string s : word2) {
            res2 += s;
        }

        return res1 == res2;
    }
};