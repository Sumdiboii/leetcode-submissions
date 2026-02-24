class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;

        while(l <= r) {                // <= to include last element
            int mid = l + (r - l) / 2; // avoid overflow

            if(nums[mid] == target) {
                return mid;             // check first
            }
            else if(nums[mid] < target) {
                l = mid + 1;
            } 
            else {
                r = mid - 1;
            }
        }

        return -1;                      // target not found
    }
};
