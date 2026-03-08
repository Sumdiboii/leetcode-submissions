class Solution {
public:
    void findMaxNSum(vector<int>& weights, int &low, int &high){
        for(int i = 0; i < weights.size();i++){
            if (low > weights[i]) low = weights[i];
            high += weights[i];
        }
    }

    bool findMinWeights(vector<int>& weights, int days, int minWeight){
        int temp = minWeight;
        int i = 0;
        while (i < weights.size() && days>0){
            if (temp < weights[i]){
                days -= 1;
                temp = minWeight;
            }
            else {
                temp -= weights[i];
                i += 1;
            }
        }
        return (i == weights.size());
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low =0, high = 0;
        int ans = 0;
        findMaxNSum(weights, low, high);
        while (low<=high){
            int mid = (low+high) / 2;
            if (findMinWeights(weights, days, mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};