#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            
            // Move string buffer directly into hash map without reallocation
            mp[key].push_back(move(s));
        }

        vector<vector<string>> result;
        result.reserve(mp.size()); // Pre-allocate outer vector memory

        for (auto& pair : mp) {
            // Move whole inner vector in O(1) time
            result.push_back(move(pair.second));
        }

        return result;
    }
};