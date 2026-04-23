class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uset;

        for( auto n : nums){

            if(uset.find(n) != uset.end()){
                return true;
            }
            uset.insert(n);
        }


        return false;
    }
};