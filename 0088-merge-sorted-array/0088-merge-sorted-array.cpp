class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;         // Pointer for last valid element in nums1
        int j = n - 1;         // Pointer for last element in nums2
        int writeIdx = m + n - 1; // Pointer for the very last slot of nums1

        // Merge backwards
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[writeIdx] = nums1[i];
                i--;
            } else {
                nums1[writeIdx] = nums2[j];
                j--;
            }
            writeIdx--;
        }

        // If nums2 still has leftovers, copy them over.
        // (Leftovers in nums1 are already in their correct places)
        while (j >= 0) {
            nums1[writeIdx] = nums2[j];
            j--;
            writeIdx--;
        }
    }
};