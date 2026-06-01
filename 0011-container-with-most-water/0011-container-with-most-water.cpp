class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n =  heights.size();
        int length = 0;
        int breadth = 0; 
        int area = 0;
        int totalarea = 0;

        int l = 0; int r = n-1;

        while(l<r){
            length = min(heights[l], heights[r]);
            breadth = r-l;

        area = length * breadth;

        totalarea = max(totalarea, area);

        if( heights[l] > heights[r]){
            r--;
        }
        else{
            l++;
        }
        }



return totalarea;

    }
};