class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int maxlen = 0;
       int l=0;
       int n = s.length();

        unordered_set<char> uset;

        for( int r = 0; r<n; r++){

            while(uset.contains(s[r])){
                uset.erase(s[l]);
                l++;
            }
            uset.insert(s[r]);

            maxlen = max(maxlen, r-l+1);
        }
        return maxlen;
    }
};
