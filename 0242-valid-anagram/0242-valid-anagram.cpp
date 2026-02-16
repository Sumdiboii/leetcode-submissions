class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char,int> freq;

        // count s
        for(char c : s) {
            freq[c]++;
        }

        // subtract t
        for(char c : t) {
            freq[c]--;
        }

        // check all zero
        for(auto &p : freq) {
            if(p.second != 0) return false;
        }

        return true;
    }
};
