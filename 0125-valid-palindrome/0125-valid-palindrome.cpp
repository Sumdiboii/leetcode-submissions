class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0; 
        int r = s.length() - 1;

        while (l < r) {
            // If left character is not alphanumeric, skip it and restart loop
            if (!isalnum(s[l])) {
                l++;
                continue; 
            }
            
            // If right character is not alphanumeric, skip it and restart loop
            if (!isalnum(s[r])) {
                r--;
                continue;
            }

            // Now both s[l] and s[r] are guaranteed to be valid alphanumeric characters
            if (tolower(s[l]) == tolower(s[r])) {
                l++; 
                r--;
            } else {
                return false;
            }
        }

        return true;
    }
};