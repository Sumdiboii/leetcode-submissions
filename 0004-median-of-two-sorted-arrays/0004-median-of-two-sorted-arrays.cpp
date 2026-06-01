class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1. Safely append all elements of nums2 into nums1
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        // 2. Sort the combined vector correctly
        sort(nums1.begin(), nums1.end());

        int len = nums1.size();

        // 3. Calculate median based on even or odd length
        if (len % 2 == 0) {
            // Use 0.5 or double casting to prevent integer division truncation
            return (nums1[len / 2 - 1] + nums1[len / 2]) / 2.0;
        } else {
            return nums1[len / 2];
        }
    }
};