class Solution {
public:
    bool isValid(string s) {
        // 1. Corrected the syntax typo ( replaced '.' with ',' )
        unordered_map<char, char> umap{ 
            {')', '('}, 
            {'}', '{'}, 
            {']', '['} 
        };
        
        stack<char> stk;
        
        for (char ch : s) {
            // If the character is a closing bracket
            if (umap.count(ch)) { 
                // 2. Simplified the logic: Check if the stack matches the map value
                if (!stk.empty() && stk.top() == umap[ch]) {
                    stk.pop();
                } else {
                    return false; // Mismatched bracket or stack was empty
                }
            } else {
                // If it's an opening bracket, push it to the stack
                stk.push(ch);
            }
        }
        
        // Return true only if all opening brackets found their pairs
        return stk.empty(); 
    }
};
