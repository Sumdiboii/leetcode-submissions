class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;

        vector<int> diff;

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i])
                diff.push_back(i);
        }

        if (diff.size() == 0)
            return true;

        if (diff.size() != 2)
            return false;

        int i = diff[0], j = diff[1];

        return s1[i] == s2[j] && s1[j] == s2[i];
    }
};
