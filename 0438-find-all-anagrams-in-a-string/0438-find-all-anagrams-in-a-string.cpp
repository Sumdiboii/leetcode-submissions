class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (m > n) return {};
        vector<int> ans;
        vector<int> cntP(26, 0), cntS(26, 0);

        for (char ch : p) cntP[ch - 'a']++;
        for (int i = 0; i < m; i++) cntS[s[i] - 'a']++;
        if (cntS == cntP) ans.push_back(0);

        for (int i = m; i < n; i++) {
            cntS[s[i] - 'a']++;
            cntS[s[i - m] - 'a']--;
            if (cntS == cntP) ans.push_back(i - m + 1);
        }

        return ans;
    }
};