class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 0, best = 0;
        for (int x : nums) {
            if (x == 1) {
                cur++;
                best = max(best, cur);
            } else {
                cur = 0;
            }
        }
        return best;
    }
    };
