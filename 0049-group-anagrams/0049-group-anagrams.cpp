class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> umap;

        for (string s : strs) {
            vector<int> freq(26, 0);

            for (char ch : s) {
                freq[ch - 'a']++;
            }

            string key = "";

            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]) + "#";
            }

            umap[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto& p : umap) {
            result.push_back(p.second);
        }

        return result;
    }
};