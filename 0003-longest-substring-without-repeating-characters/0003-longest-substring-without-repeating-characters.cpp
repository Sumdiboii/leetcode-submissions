class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;

        unordered_set<int> uset;
        int l = 0;
        for (int r = 0; r < n; r++) {

            while(uset.contains(s[r])){
                
                uset.erase(s[l]);
               

                l++;
            }

            uset.insert(s[r]);
            maxlen = max( maxlen , r-l+1);
        }

        return maxlen;
    }
};