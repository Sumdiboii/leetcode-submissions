class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxCount = 0;

        for (int i = 0; i < n; i++) {

            // If this 1 is the START of a streak
            if (nums[i] == 1 && (i == 0 || nums[i - 1] == 0)) {
                int count = 1;

                // walk forward while 1s continue
                while (i + count < n && nums[i + count] == 1) {
                    count++;
                }

                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};
