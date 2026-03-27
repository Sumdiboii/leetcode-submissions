class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> prefix(n+1);
        int alt = 0;
        int nullval = 0;

        prefix[0] = nullval;

        for( int i = 1; i<= n  ; i++){
            prefix[i] = prefix[i-1] + gain[i-1];
            alt = max( alt, prefix[i] );
        }

        return alt;
    }
};