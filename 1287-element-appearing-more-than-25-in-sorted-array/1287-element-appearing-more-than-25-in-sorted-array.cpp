class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];

        int t = n/4; // threshold

        unordered_map<int,int> freq;
        for(int x : arr) freq[x]++;

        // iterate through array in order to respect first occurrence
        for(int x : arr) {
            if(freq[x] > t) return x;
        }

        return -1; // safety, should never happen
    }
};