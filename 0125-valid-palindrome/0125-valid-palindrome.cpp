class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {

            // skip non-alphanumeric (left)
            while (left < right && !isalnum(s[left])) left++;

            // skip non-alphanumeric (right)
            while (left < right && !isalnum(s[right])) right--;

            // compare lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};