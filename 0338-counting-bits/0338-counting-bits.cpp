class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> results;
        int cnt=0;

        for( int i = 0; i<=n; i++){
            cnt = __builtin_popcount(i);
            results.push_back(cnt);
        }

        return results;
    }
};