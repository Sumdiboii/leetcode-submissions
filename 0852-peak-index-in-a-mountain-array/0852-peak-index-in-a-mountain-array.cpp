class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // increasing slope
                low = mid + 1;
            } else {
                // decreasing slope
                high = mid;
            }
        }
        return low; // peak index
    }
};