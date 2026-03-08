class Solution {
public:
    int arrangeCoins(int n) {
        long long left=1,right=n;
        int ans=1;
        while(left<=right){
            long long mid = left + (right-left)/2;
            long long sum = (mid*(mid+1))/2;
            if(sum<=n){
                ans = mid;
                left = mid+1;
            }else{
                right = mid -1;
            }
        }
        return ans;
    }
};