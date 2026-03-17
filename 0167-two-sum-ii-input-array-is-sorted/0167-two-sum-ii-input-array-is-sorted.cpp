// static const auto fast_io = [](){
//     ios :: sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return 0;

// }();

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;

        while(left<right){
            if (numbers[left]+numbers[right]<target){
                left++;
                continue;
            }

            if (numbers[left]+numbers[right]>target){
                right--;
                continue;
            }

            if(numbers[left]+ numbers[right]==target){
                return{left+1, right+1};
            }
        }
        return{};
    }
};
