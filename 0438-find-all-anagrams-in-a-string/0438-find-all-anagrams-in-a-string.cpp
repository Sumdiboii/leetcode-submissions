class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        if (m > n) return {};

        unordered_map<char, int> umap1, umap2;
        vector<int> ans;

        for (char ch : p) umap1[ch]++;

        // Build first window
        for (int r = 0; r < m; r++) umap2[s[r]]++;
        if (umap1 == umap2) ans.push_back(0);

        // Slide window
        for (int r = m; r < n; r++) {
            umap2[s[r]]++;                // add new char
            umap2[s[r - m]]--;            // remove left char
            if (umap2[s[r - m]] == 0) umap2.erase(s[r - m]); // erase zero count

            if (umap1 == umap2) ans.push_back(r - m + 1); // push start index
        }

        return ans;
    }
};