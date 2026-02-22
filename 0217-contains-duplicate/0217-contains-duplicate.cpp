class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_set<int> uset ;

       for( int n : nums) {
            if( uset.contains(n)){
                return true;

            }

            uset.insert(n);
       }
        
        return false;
    }
};