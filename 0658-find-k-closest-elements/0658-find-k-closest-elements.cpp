class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - 1;

        // Keep shrinking the window from the outside until its size is exactly k
        while (r - l + 1 > k) {
            // Calculate absolute distances from x
            int dist_l = abs(arr[l] - x);
            int dist_r = abs(arr[r] - x);

            // If left element is closer or equally close, it's preferred.
            // So we eliminate the right element.
            if (dist_l <= dist_r) {
                r--;
            } else {
                l++;
            }
        }

        // The remaining window from index l to r is exactly your answer!
        // We can build the result vector using the vector constructor.
        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};
