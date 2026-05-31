class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        // Edge case: s cannot be a subsequence of t if it's longer
        if (n > m) return false;

        int i = 0; // Pointer for s
        int j = 0; // Pointer for t

        // Traverse both strings
        while (i < n && j < m) {
            // If characters match, move the pointer in s
            if (s[i] == t[j]) {
                i++;
            }
            // Always move the pointer in t
            j++;
        }

        // If we successfully matched all characters of s, i will equal n
        return i >= n;
    }
};