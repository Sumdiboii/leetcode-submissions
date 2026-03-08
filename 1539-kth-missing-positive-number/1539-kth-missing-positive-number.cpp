class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 1;
        int j = 0;
        int n = 0;
        while (n < k) {
            if (j < arr.size() && i == arr[j]) {
                i++;
                j++;
            } else {
                i++;
                n++;
            }
        }
        return i-1;
    }
};