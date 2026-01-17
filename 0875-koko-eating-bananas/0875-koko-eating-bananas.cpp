class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int k = (l + r) / 2;

            long long timetotal = 0;
            for (int p : piles) {
                timetotal += ceil(static_cast<double>(p) / k);
            }

            if (timetotal <= h) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }

        return res;
    }
};
