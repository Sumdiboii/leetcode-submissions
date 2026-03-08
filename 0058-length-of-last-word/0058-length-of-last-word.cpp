class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int cnt = 0;
        int i = n - 1;

        // skip trailing spaces
        while(i >= 0 && s[i] == ' ') {
            i--;
        }

        // count last word
        while(i >= 0 && s[i] != ' ') {
            cnt++;
            i--;
        }

        return cnt;
    }
};