class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }

        int l = 1;
        int r = x / 2;
        int ans = 0; // Create a variable to hold our best valid guess

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (m <= x / m) {
                ans = m;   // 1. This 'm' is valid, save it!
                l = m + 1; // 2. Keep searching right to find a LARGER valid integer
            } else {
                r = m - 1; // 'm' is too big, search left
            }
        }

        return ans; // Return the absolute largest valid integer we found
    }
};
