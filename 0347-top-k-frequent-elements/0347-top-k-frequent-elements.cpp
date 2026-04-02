class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> um;

        for (int num: nums) {
            um[num]++;
        }

        for (auto itr: um) {
            pq.push({itr.second, itr.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> answer;
        while (!pq.empty()) {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
};