class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> temp;

        for( int i = 0; i< nums.size(); i++){
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());

        int l = 0; 
        int r = temp.size() - 1;

        while(l<r){
            if(temp[l].first + temp[r].first == target){
                return {temp[l].second, temp[r].second};
            }else if(temp[l].first + temp[r].first > target){
                r--;
            }else{
                l++;
            }
        }

        return {};
    }
};