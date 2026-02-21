class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> lastIndex;

        int l = 0;
        int maxlen = 0;

        for(int r = 0; r < s.length(); r++) {

            if(lastIndex.contains(s[r]) && lastIndex[s[r]] >= l) {
                l = lastIndex[s[r]] + 1;
            }

            lastIndex[s[r]] = r;

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
