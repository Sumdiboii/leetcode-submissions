class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        int x = min(n, m);

        string res = "";

        for (int i = 0; i < x; i++) {
            res += word1[i];
            res += word2[i];
        }



        if (n > m) {
            for (int i = m; i < n; i++) {
                res += word1[i];
            }
        } else {
            for (int i = n; i < m; i++) {
                res += word2[i];
            }
        }
        return res;
    }
};