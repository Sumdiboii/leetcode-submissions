class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        sort(people.begin(), people.end());

        int l = 0;
        int r = n - 1;
        int cnt = 0;

        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                l++;
                r--;
            } else {
                r--;
            }

            cnt++;
        }
        return cnt;
    }
};