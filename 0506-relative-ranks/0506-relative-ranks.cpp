class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        priority_queue<pair<int, int>> pq;
        vector<string> res(n);

        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        int rank = 1;

        while (!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();

            if (rank == 1) {
                res[idx] = "Gold Medal";
            } 
            else if (rank == 2) {
                res[idx] = "Silver Medal";
            } 
            else if (rank == 3) {
                res[idx] = "Bronze Medal";
            } 
            else {
                res[idx] = to_string(rank);
            }

            rank++;
        }

        return res;
    }
};