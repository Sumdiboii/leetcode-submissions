class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> uset;

        for ( int n : nums ){

            if( uset.count(n)){
                return n;
            }
            uset.insert(n);
        }

        return 0;
    }


};