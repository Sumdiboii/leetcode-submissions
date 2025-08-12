class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       //optimal approach by unordered set

       unordered_set<int> seen;

       for(int n : nums){
        if(seen.count(n)){
            return true;
        }
        seen.insert(n);
       }
       return false;
    }
};
