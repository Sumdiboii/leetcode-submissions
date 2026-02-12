class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<char, int> mp;
        int sz = s.size(), ans = 0;
        
        // Try all possible substrings
        for(int i = 0; i < sz; i++) {
            mp = {};  // Reset map for each starting position
            
            for(int j = i; j < sz; j++) {
                mp[s[j]]++;
                
                // Check if current substring is balanced
                bool flag = true;
                int cnt = mp[s[j]];  // Get frequency of current character
                
                for(auto x : mp) {
                    if(x.second != cnt) {
                        flag = false;
                        break;
                    }
                }
                
                if(flag) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        
        return ans;
    }
};