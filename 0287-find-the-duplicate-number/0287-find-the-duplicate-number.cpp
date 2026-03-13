class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow!=fast);
        //{
        //     slow = nums[slow];
        //     fast = nums[nums[fast]];
        // }
        int prev = 0;
        slow = 0;
        while(slow!=fast){
            prev = slow;
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};