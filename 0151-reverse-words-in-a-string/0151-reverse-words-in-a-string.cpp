class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, ans;

        while(ss >> word) {           // auto-skips extra spaces
            ans = word + " " + ans;   // prepend
        }

        if(!ans.empty()) ans.pop_back(); // remove last space
        return ans;
    }
};
