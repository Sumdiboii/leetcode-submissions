class Solution {
public:

    // maps character to index 0..51
    int getIdx(char ch) {
        if (ch >= 'a' && ch <= 'z') return ch - 'a';
        if (ch >= 'A' && ch <= 'Z') return 26 + (ch - 'A');
        return -1;
    }

    // checks if current window satisfies t frequency
    bool contains(vector<int>& scnt, vector<int>& tcnt) {
        for (int i = 0; i < 52; i++) {
            if (scnt[i] < tcnt[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {

        int m = s.length();
        int n = t.length();

        if (n > m) return "";

        vector<int> scnt(52, 0);
        vector<int> tcnt(52, 0);

        // Step 1: Build frequency of t
        for (char ch : t) {
            int idx = getIdx(ch);
            if (idx != -1)
                tcnt[idx]++;
        }

        int l = 0;
        int minLen = INT_MAX;
        int start = 0;

        // Step 2: Expand window
        for (int r = 0; r < m; r++) {

            int idx = getIdx(s[r]);
            if (idx != -1)
                scnt[idx]++;

            // Step 3: Shrink window while valid
            while (contains(scnt, tcnt)) {

                // update minimum
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // remove left char
                int leftIdx = getIdx(s[l]);
                if (leftIdx != -1)
                    scnt[leftIdx]--;

                l++;
            }
        }

        // Step 4: Return result
        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};