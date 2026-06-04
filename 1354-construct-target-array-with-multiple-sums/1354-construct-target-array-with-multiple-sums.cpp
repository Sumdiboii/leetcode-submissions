#include <vector>
#include <queue>
#include <numeric>

class Solution {
public:
    bool isPossible(std::vector<int>& target) {
        if (target.size() == 1) {
            return target[0] == 1;
        }

        std::priority_queue<int> max_heap(target.begin(), target.end());
        long long total_sum = 0;
        for (int num : target) {
            total_sum += num;
        }

        while (true) {
            int max_val = max_heap.top();
            max_heap.pop();
            
            long long other_sum = total_sum - max_val;

            // Base cases for success
            if (max_val == 1 || other_sum == 1) {
                return true;
            }

            // Failure conditions
            if (other_sum == 0 || max_val <= other_sum) {
                return false;
            }

            int remainder = max_val % other_sum;

            if (remainder == 0) {
                return false;
            }

            total_sum = other_sum + remainder;
            max_heap.push(remainder);
        }
    }
};