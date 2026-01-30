class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: Quick length check
        if (s.size() != t.size()) 
            return false;  // Strings of different lengths cannot be anagrams

        // Step 2: Create frequency array for 26 lowercase letters
        vector<int> freq(26, 0);

        // Step 3: Count occurrences of each character in s
        for (char c : s) {
            freq[c - 'a']++;  // Map 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
        }

        // Step 4: Subtract occurrences using t
        for (char c : t) {
            freq[c - 'a']--;  // Decrement count for each character in t
        }

        // Step 5: Validate the frequency array
        for (int count : freq) {
            if (count != 0) 
                return false;  // Mismatch found, not an anagram
        }

        // Step 6: If all counts are zero, strings are anagrams
        return true;
    }
};
