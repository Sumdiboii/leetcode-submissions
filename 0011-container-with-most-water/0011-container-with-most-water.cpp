class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int l =0 ;
        int r = n-1;

        int length=0;
        int breadth =0;
        int area =0;
        int maxarea = 0;

        while(l<r){

            length = min(height[l], height[r]);
            breadth = r-l;
            area = length * breadth;

            maxarea = max(maxarea, area);

            if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
            }


        }
        return maxarea;
    }
};