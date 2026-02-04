class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> numset;
        for(int num:nums){

            if(numset.contains(num)){
                int res=num;
                return res;
            }
            numset.insert(num);
        }
        return 0;

    }
};
