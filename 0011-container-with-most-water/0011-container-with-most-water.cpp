class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0; //first bar
        int r=heights.size()-1; //last bar
        int def=0;

        while(l<r){
            int area= min(heights[l], heights[r])*(r-l);
            def=max(area,def);

            if(heights[l]<heights[r]){
                l++;
            }
            else r--;

           
        }
         return def;
        
    }
};
