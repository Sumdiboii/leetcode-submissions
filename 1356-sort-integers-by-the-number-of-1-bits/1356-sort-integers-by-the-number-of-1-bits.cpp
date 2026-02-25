class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        // store {bitcount, number}
        vector<pair<int,int>> temp;

        for (int i = 0; i < arr.size(); i++) {
            int cnt = __builtin_popcount(arr[i]);
            temp.push_back({cnt, arr[i]});
        }

        // sort by bitcount first, then by number
        sort(temp.begin(), temp.end());

        // extract sorted numbers
        vector<int> result;
        for (auto &p : temp) {
            result.push_back(p.second);
        }

        return result;
    }
};