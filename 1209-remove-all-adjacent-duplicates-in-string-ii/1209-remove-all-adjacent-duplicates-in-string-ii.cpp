class Solution {
public:
    string removeDuplicates(string s, int k) {
        // pair<char, count>
        vector<pair<char, int>> st;
        
        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                // Increment count of the top element
                st.back().second++;
            } else {
                // New character encountered
                st.push_back({c, 1});
            }
            
            // If count reaches k, remove it
            if (st.back().second == k) {
                st.pop_back();
            }
        }
        
        // Build the result string
        string result = "";
        for (auto& p : st) {
            result.append(p.second, p.first);
        }
        
        return result;
    }
};