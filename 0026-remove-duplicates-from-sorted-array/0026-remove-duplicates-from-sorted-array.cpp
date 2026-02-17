class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int l = 0; // points to last unique element
        for (int r = 1; r < nums.size(); r++) {
            if (nums[r] != nums[l]) {
                l++;
                nums[l] = nums[r]; // move unique element forward
            }
        }
        return l + 1; // length of unique elements
    }
};
