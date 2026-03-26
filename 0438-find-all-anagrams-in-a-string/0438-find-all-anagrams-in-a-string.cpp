class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int n = s.length();
        int m = p.length();

        vector<int> freqP(26,0);
        vector<int> freqS(26,0);
        vector<int> res;

         if (m > n) return {};

        for (char ch : p) {
            freqP[ch - 'a']++; // created a frequancy count to iterate with
        }

        for (int i = 0; i < m; i++) {
            freqS[s[i] - 'a']++;
        }

        if (freqS == freqP) {
            res.push_back(0);
        }

        for (int i = m; i < n; i++) {
            freqS[s[i] - 'a']++;
            freqS[s[i - m] - 'a']--;

            if (freqS == freqP) {
                res.push_back(i - m + 1);
            }
        }

        return res;
    }
};