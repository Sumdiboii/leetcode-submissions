class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0; // position to place next valid element

        for (int n : nums) {
            if (k < 2 || nums[k - 2] != n) {
                nums[k] = n;
                k++;
            }
        }

        return k;
    }
};