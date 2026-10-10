class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;

        int sz = m + n - 1;
        while (i >= 0 && j >= 0) {

            if (nums1[i] > nums2[j]) {
                nums1[sz] = nums1[i];
                sz--;
                i--;
            } else {
                nums1[sz] = nums2[j];
                sz--;
                j--;
            }
        }
        // Only copy the remaining elements of nums2 if there are any left
        while (j >= 0) {
            nums1[sz] = nums2[j];
            sz--;
            j--;
        }
    }
};