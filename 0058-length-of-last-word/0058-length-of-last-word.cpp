class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int cnt = 0;

        // 1. Skip trailing non-alphabet characters (like spaces) safely
        while (i >= 0 && !isalpha(s[i])) {
            i--;
        }

        // 2. Count the characters of the last word
        while (i >= 0 && isalpha(s[i])) {
            cnt++;
            i--;
        }

        return cnt;
    }
};
