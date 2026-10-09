#include <iostream>
#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = (int)s.length() - 1;

        while (i < j) {
            // Skip non-alphanumeric characters from the left
            if (!isalnum(s[i])) {
                i++;
            }
            // Skip non-alphanumeric characters from the right
            else if (!isalnum(s[j])) {
                j--;
            }
            // Compare lowercase versions of the characters
            else {
                if (tolower(s[i]) != tolower(s[j])) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
};
