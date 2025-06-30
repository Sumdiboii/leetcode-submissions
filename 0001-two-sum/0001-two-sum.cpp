class Solution{            //Class Solution for the C++ Code 
    public:                //visibility mode to allow public access of class contents

    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> sum;

    for (int i = 0; i < nums.size(); i++) {
        int comp = target - nums[i];

        if (sum.find(comp) != sum.end()) {
            return {sum[comp], i};
        }

        sum[nums[i]] = i;
    }

    return {};
}
};