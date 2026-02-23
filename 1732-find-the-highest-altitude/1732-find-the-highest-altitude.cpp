class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int peak = 0;

        vector<int> prefix(n+1);
        prefix[0] = gain[0];

        for( int i = 1 ; i<n ; i++){
            prefix[i] = gain[i]+ prefix[i-1];
        } 

        peak = *max_element(prefix.begin(), prefix.end());

        return peak;
    }
};