#include <vector>
#include <algorithm>

class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        int total_time = 0;
        int target_tickets = tickets[k];
        
        for (int i = 0; i < tickets.size(); ++i) {
            if (i <= k) {
                // People before or at index k
                total_time += std::min(tickets[i], target_tickets);
            } else {
                // People after index k
                total_time += std::min(tickets[i], target_tickets - 1);
            }
        }
        
        return total_time;
    }
};