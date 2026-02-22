class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int subarrcnt = 0;
        int threshold_val = threshold * k;
        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        if (sum >= threshold_val) {
            subarrcnt++;
        }

        for (int i = k; i < n; i++) {
            sum += arr[i];
            sum -= arr[i - k];

            if (sum >= threshold_val) {
                subarrcnt++;
            }
        }

        return subarrcnt;
    }
};