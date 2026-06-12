#include <string>
#include <vector>
#include <numeric>

class Solution {
public:
    long long sumScores(std::string s) {
        int n = s.length();
        std::vector<int> z(n, 0);
        
        // Z-array always has z[0] = n because the full string 
        // matches itself completely.
        z[0] = n;
        
        // [l, r] represents the window with the furthest right reach
        int l = 0, r = 0;
        
        for (int i = 1; i < n; i++) {
            // If i is within the current window [l, r]
            if (i <= r) {
                // Try to copy the value from the prefix mapping
                z[i] = std::min(r - i + 1, z[i - l]);
            }
            
            // Explicitly match characters to extend the window
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            
            // If the window extended past r, update the boundaries
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        
        // Accumulate the scores. Use long long to avoid integer overflow.
        long long total_score = 0;
        for (int score : z) {
            total_score += score;
        }
        
        return total_score;
    }
};