class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l < r) {
            int m = l + (r - l) / 2;
            
            // If the middle element is greater than the rightmost element,
            // the minimum element is in the right half.
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                // Otherwise, the minimum is in the left half including mid.
                r = m;
            }
        }
        
        // When l == r, we point to the minimum element.
        return nums[l];
    }
};
