#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
    // Structure for our Monotonic Stacks to keep track of interval sums
    struct Element {
        int start_idx;
        int end_idx;
        long long val;
        long long pref_contrib;
    };

    // Helper: Count how many subarrays have value >= V
    long long countSubarrays(const vector<int>& nums, long long V) {
        int n = nums.size();
        long long count = 0;
        int left = 0;
        deque<int> max_dq, min_dq;

        for (int r = 0; r < n; ++r) {
            // Maintain sliding window maximums and minimums
            while (!max_dq.empty() && nums[max_dq.back()] <= nums[r]) max_dq.pop_back();
            max_dq.push_back(r);
            
            while (!min_dq.empty() && nums[min_dq.back()] >= nums[r]) min_dq.pop_back();
            min_dq.push_back(r);

            // Shrink window while the difference >= V
            while (!max_dq.empty() && !min_dq.empty() && nums[max_dq.front()] - nums[min_dq.front()] >= V) {
                left++;
                if (max_dq.front() < left) max_dq.pop_front();
                if (min_dq.front() < left) min_dq.pop_front();
            }
            // `left` is exactly the number of valid starting points for this `r`
            count += left; 
        }
        return count;
    }

    // Helper: Query the sum of elements from index 0 to L using the Monotonic Stack
    long long queryStack(int L, const vector<Element>& stk) {
        if (L < 0) return 0;
        
        // Binary search to find the block containing the index L
        int low = 0, high = stk.size() - 1, idx = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (stk[mid].start_idx <= L) {
                idx = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        if (idx == -1) return 0;
        long long sum = (idx > 0 ? stk[idx - 1].pref_contrib : 0);
        sum += (long long)(min(L, stk[idx].end_idx) - stk[idx].start_idx + 1) * stk[idx].val;
        return sum;
    }

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        // Step 1: Binary search to find the exact k-th largest value
        long long low = 0, high = 1e9, V_star = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countSubarrays(nums, mid) >= k) {
                V_star = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        int n = nums.size();
        long long total_sum = 0, count = 0;
        int left = 0;
        deque<int> max_dq, min_dq;
        vector<Element> max_stack, min_stack;

        // Step 2: Sweep the array to compute the actual sums
        for (int r = 0; r < n; ++r) {
            
            // --- Update Max Stack with Prefix Data ---
            int start = r;
            while (!max_stack.empty() && max_stack.back().val <= nums[r]) {
                start = max_stack.back().start_idx;
                max_stack.pop_back();
            }
            long long prev_pref = max_stack.empty() ? 0 : max_stack.back().pref_contrib;
            long long contrib = (long long)(r - start + 1) * nums[r];
            max_stack.push_back({start, r, nums[r], prev_pref + contrib});

            // --- Update Min Stack with Prefix Data ---
            start = r;
            while (!min_stack.empty() && min_stack.back().val >= nums[r]) {
                start = min_stack.back().start_idx;
                min_stack.pop_back();
            }
            prev_pref = min_stack.empty() ? 0 : min_stack.back().pref_contrib;
            contrib = (long long)(r - start + 1) * nums[r];
            min_stack.push_back({start, r, nums[r], prev_pref + contrib});

            // --- Update Sliding Window ---
            while (!max_dq.empty() && nums[max_dq.back()] <= nums[r]) max_dq.pop_back();
            max_dq.push_back(r);
            
            while (!min_dq.empty() && nums[min_dq.back()] >= nums[r]) min_dq.pop_back();
            min_dq.push_back(r);

            // Shrink window while difference >= V_star
            while (!max_dq.empty() && !min_dq.empty() && nums[max_dq.front()] - nums[min_dq.front()] >= V_star) {
                left++;
                if (max_dq.front() < left) max_dq.pop_front();
                if (min_dq.front() < left) min_dq.pop_front();
            }

            count += left;
            
            // Query the precise sum of maxes and mins for all valid subarrays ending at `r`
            total_sum += queryStack(left - 1, max_stack) - queryStack(left - 1, min_stack);
        }

        // Step 3: Exact target correlation
        // If we counted more subarrays than `k` (because multiple had exactly V_star difference)
        return total_sum - (count - k) * V_star;
    }
};