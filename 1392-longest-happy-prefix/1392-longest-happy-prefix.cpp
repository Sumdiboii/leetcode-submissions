#include <string>
#include <vector>

class Solution {
public:
    std::string longestPrefix(std::string s) {
        int n = s.length();
        if (n <= 1) return "";
        
        // lps[i] will store the length of the longest happy prefix for substring s[0...i]
        std::vector<int> lps(n, 0);
        
        // Length of the previous longest prefix suffix
        int len = 0; 
        int i = 1;
        
        // Loop calculates lps[i] for i = 1 to n-1
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                // This is tricky. Consider the example "ababe......ababc", len is 4.
                // If s[i] != s[len], we do NOT look at lps[0]. We backtrack to lps[len-1].
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // The last element of the lps array contains the length of the 
        // longest proper prefix which is also a suffix for the entire string.
        int longest_len = lps[n - 1];
        
        return s.substr(0, longest_len);
    }
};