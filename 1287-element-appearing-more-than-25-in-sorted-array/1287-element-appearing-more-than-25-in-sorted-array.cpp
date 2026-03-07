class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int t = n / 4; // threshold

        int count = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i] == arr[i-1]) {
                count++;
                if(count > t) return arr[i];
            } else {
                count = 1;
            }
        }

        return arr[0]; // first element covers >25% if array size is 1 or extreme case
    }
};