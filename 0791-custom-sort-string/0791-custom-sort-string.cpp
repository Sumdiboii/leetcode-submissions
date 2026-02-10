class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);

        // Count characters of s
        for (char c : s) freq[c - 'a']++;

        string ans = "";

        // Place chars in the custom order
        for (char c : order) {
            while (freq[c - 'a']--) {
                ans.push_back(c);
            }
        }

        // Append leftover characters
        for (int i = 0; i < 26; i++) {
            while (freq[i]-- > 0) {
                ans.push_back('a' + i);
            }
        }

        return ans;
    }
};
