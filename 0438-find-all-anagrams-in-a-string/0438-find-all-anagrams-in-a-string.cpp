class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> result;

        if (s.size() < p.size())
            return result;

        vector<int> pCount(26, 0);
        vector<int> windowCount(26, 0);

        // count frequency of p
        for (char c : p)
            pCount[c - 'a']++;

        int k = p.size();

        // first window
        for (int i = 0; i < k; i++)
            windowCount[s[i] - 'a']++;

        if (windowCount == pCount)
            result.push_back(0);

        // slide window
        for (int i = k; i < s.size(); i++) {

            // add incoming character
            windowCount[s[i] - 'a']++;

            // remove outgoing character
            windowCount[s[i - k] - 'a']--;

            if (windowCount == pCount)
                result.push_back(i - k + 1);
        }

        return result;
    }
};
