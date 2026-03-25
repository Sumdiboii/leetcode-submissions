class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int idx = abs(nums[i]);

            if(nums[idx] < 0)
                return idx;  // already visited!

            nums[idx] = -nums[idx];  // mark visited
        }
        return -1;
    }
};