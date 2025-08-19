class Solution {
public:
//brute force approach 
    int maxProfit(vector<int>& prices) {
        int max_p=0;
        int min_p=prices[0];

        for(int num : prices){
            max_p= max(max_p, num-min_p);
            min_p= min(min_p, num);
        }
        return max_p;
    }
};