class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        for (int n : asteroids) {
            bool destroyed = false;

            // Collision condition: Top of stack moves right (> 0) and current moves left (< 0)
            while (!stk.empty() && stk.top() > 0 && n < 0) {
                if (abs(n) > stk.top()) {
                    // Top asteroid explodes, current asteroid keeps moving left
                    stk.pop();
                } else if (abs(n) == stk.top()) {
                    // Both explode
                    stk.pop();
                    destroyed = true;
                    break;
                } else {
                    // Current asteroid explodes
                    destroyed = true;
                    break;
                }
            }

            // If current asteroid wasn't destroyed, push it to stack
            if (!destroyed) {
                stk.push(n);
            }
        }

        // Collect remaining asteroids from stack
        vector<int> res(stk.size());
        for (int i = stk.size() - 1; i >= 0; i--) {
            res[i] = stk.top();
            stk.pop();
        }

        return res;
    }
};