class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars; // stores characters in current window
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            // If current char already exists in window, remove from left until it's gone
            while (chars.count(s[right])) {
                chars.erase(s[left]);
                left++;
            }

            // Add current char to window
            chars.insert(s[right]);

            // Update max length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
