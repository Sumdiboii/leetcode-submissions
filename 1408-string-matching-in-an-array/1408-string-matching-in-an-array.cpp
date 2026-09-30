class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        
        // Sort by length (shortest first)
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        
        int n = words.size();
        for (int i = 0; i < n; i++) {
            // Only check strings that are longer (or equal) than words[i]
            for (int j = i + 1; j < n; j++) {
                if (words[j].find(words[i]) != string::npos) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};