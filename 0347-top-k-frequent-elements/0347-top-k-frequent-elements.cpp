// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
//         unordered_map<int, int> um;

//         for (int num: nums) {
//             um[num]++;
//         }

//         for (auto itr: um) {
//             pq.push({itr.second, itr.first});
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }

//         vector<int> answer;
//         while (!pq.empty()) {
//             answer.push_back(pq.top().second);
//             pq.pop();
//         }
//         return answer;
//     }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        // Bucket sort: index is frequency, value is list of numbers with that frequency
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, freq] : count) {
            buckets[freq].push_back(num);
        }

        vector<int> result;
        // Traverse from highest frequency to lowest
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        return result;
    }
};
