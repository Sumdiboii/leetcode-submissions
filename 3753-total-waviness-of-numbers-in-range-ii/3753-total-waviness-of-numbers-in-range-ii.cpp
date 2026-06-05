#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// DP table: [idx: 16][prev: 11][prev2: 11][is_less: 2][is_started: 2]
// Each cell stores a pair: {count, total_waviness}
pair<long long, long long> memo[16][11][11][2][2];
bool visited[16][11][11][2][2];

class Solution {
private:
    string num_str;

    pair<long long, long long> solve_dp(int idx, int prev, int prev2, bool is_less, bool is_started) {
        // Base case: if we reach the end, we've successfully formed 1 valid number with 0 extra waviness
        if (idx == num_str.length()) {
            return {1LL, 0LL};
        }

        // Map sentinel -1 to index 10 for safe array mapping
        int p_idx = (prev == -1) ? 10 : prev;
        int p2_idx = (prev2 == -1) ? 10 : prev2;

        if (visited[idx][p_idx][p2_idx][is_less][is_started]) {
            return memo[idx][p_idx][p2_idx][is_less][is_started];
        }

        long long total_count = 0;
        long long total_wave = 0;

        int limit = is_less ? 9 : (num_str[idx] - '0');

        for (int d = 0; d <= limit; ++d) {
            bool next_less = is_less || (d < limit);
            bool next_started = is_started || (d > 0);

            int next_prev = next_started ? d : -1;
            int next_prev2 = next_started ? prev : -1;

            // Compute transition
            auto [next_count, next_wave] = solve_dp(idx + 1, next_prev, next_prev2, next_less, next_started);

            // Check if the *prev* digit forms a peak or a valley with *prev2* and the current digit *d*
            bool is_peak_or_valley = false;
            if (is_started && prev2 != -1 && prev != -1) {
                if ((prev > prev2 && prev > d) || (prev < prev2 && prev < d)) {
                    is_peak_or_valley = true;
                }
            }

            total_count += next_count;
            total_wave += next_wave;
            if (is_peak_or_valley) {
                total_wave += next_count; 
            }
        }

        visited[idx][p_idx][p2_idx][is_less][is_started] = true;
        return memo[idx][p_idx][p2_idx][is_less][is_started] = {total_count, total_wave};
    }

    long long get_total_waviness(long long n) {
        if (n < 100) return 0; // No waviness possible below 3 digits
        
        num_str = to_string(n);
        memset(visited, false, sizeof(visited));
        
        return solve_dp(0, -1, -1, false, false).second;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return get_total_waviness(num2) - get_total_waviness(num1 - 1);
    }
};