class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area =0; 
        int maxarea = 0;

        int l =0; 
        int r = n-1;

        while( l<r){

            int minnum = min(height[l], height[r]);
            area = minnum * (r-l);

            maxarea = max( maxarea, area);


            if( height[l]> height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return maxarea;
    }
};