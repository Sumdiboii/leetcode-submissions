class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = *max_element(candies.begin(), candies.end());
        int n=candies.size();
        vector<bool>vt;
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxi){
                vt.push_back(true);
            }
            else vt.push_back(false);
        }
        return vt;
    }
};