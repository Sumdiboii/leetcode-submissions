class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int area = 0;
        int maxarea = 0;
        int height = 0;

        while (l < r) {
            height = min(heights[l], heights[r]);
            area = height * (r - l);

            if (heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }

            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};
