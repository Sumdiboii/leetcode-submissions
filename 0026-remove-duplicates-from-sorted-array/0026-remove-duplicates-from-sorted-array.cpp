class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle edge case of an empty array.

        int count = 1;  // Start from 1 since the first element is always unique

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[count] = nums[i];  // Place the unique element at the 'count' index
                count++;
            }
        }
        return count;
    }
};