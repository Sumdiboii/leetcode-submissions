class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> freq(26, 0);

        int l = 0;
        int maxFreq = 0;
        int maxlen = 0;

        for(int r = 0; r < s.length(); r++) {

            freq[s[r] - 'A']++;

            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            int windowSize = r - l + 1;

            if(windowSize - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
