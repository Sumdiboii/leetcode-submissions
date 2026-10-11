class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> stk; // Stores only indices now
        
        for (int i = 0; i < n; i++) {
            // Look up the temperature using the index at the top of the stack
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int prevIndex = stk.top();
                stk.pop();
                res[prevIndex] = i - prevIndex;
            }
            stk.push(i);
        }
        return res;
    }
};
