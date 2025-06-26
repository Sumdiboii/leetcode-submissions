class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int ans = 0;
        long long cv = 0;
        long long pov2 = 1;
        for(int i = n-1; i >= 0; i--)
        {
            if(s[i] == '0') ans++;
            else
            {
                if(cv + pov2 <= k)
                {
                    cv += pov2;
                    ans++;
                }
            }
            if(pov2 <= k) pov2 *= 2;
        }
        return ans;
    }
};