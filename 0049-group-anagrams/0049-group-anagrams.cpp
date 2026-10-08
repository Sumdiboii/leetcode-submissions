class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        
        // 1. Group words by their sorted representations
        for (string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            umap[temp].push_back(s); // Fixed syntax: push_back instead of pushback
        }
        
        // 2. Extract grouped values from the map into the result vector
        vector<vector<string>> result;
        for (auto pair : umap) {
            result.push_back(pair.second);
        }
        
        return result; // Fixed syntax: added missing return variable
    }
};
