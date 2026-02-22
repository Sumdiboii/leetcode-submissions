class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int vowelcnt = 0;
        int maxvowelcnt = 0;

        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                    vowelcnt++;
                    maxvowelcnt = vowelcnt;
            }
        }

        for (int i = k; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                    vowelcnt++;
                    
            }

             if (s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' ||
                s[i-k] == 'u') {
                    vowelcnt--;

                    // maxvowelcnt = max(maxvowelcnt, vowelcnt);
            }

            maxvowelcnt = max(maxvowelcnt, vowelcnt);

        }
        return maxvowelcnt;
    }
};