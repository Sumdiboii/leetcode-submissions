class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> umap = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char ch : s) {
            if (umap.contains(ch)) {
                if (!st.empty() && st.top() == umap[ch]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(ch);
            }
        }
        return st.empty();
    }
};