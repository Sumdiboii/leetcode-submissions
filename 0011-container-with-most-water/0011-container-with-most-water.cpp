class Solution {
public:
    int maxArea(vector<int>& height) {
        auto& h = height;

        int n = h.size();
        int left =0;
        int right = n-1;
        int area = 0;
        int maxarea = 0;

        int l = 0;
        int b = 0;

        while(left<right){
            l = min(h[left], h[right]);
            b = right-left;
            area = l* b;

            if(h[left] >= h[right]){
                right--;
            }
            else{
                left++;
            }

            maxarea = max( maxarea, area);
        }

        return maxarea;
    }
};