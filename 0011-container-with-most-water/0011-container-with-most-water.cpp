class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int n = height.size();
        int j = n-1;

        int maxarea = 0;
        int area = 0;

        int heightt = 0;
        int width = 0;

        while(i<j){
            heightt = min(height[i], height[j]);
            width = j - i;

            area = heightt * width;

            maxarea = max(maxarea, area);

            if(height[i] > height[j]){
                j--;
            }else{
                i++;
            }

        }

        return maxarea;
    }
};