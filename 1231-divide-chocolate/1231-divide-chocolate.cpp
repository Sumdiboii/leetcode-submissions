class Solution {
private:
    /**
     * Greedy Check: Can we cut the chocolate into at least 'k' pieces 
     * such that every piece has a total sweetness >= minTarget?
     * * 
     * @param sweetness     The array of chunk values.
     * @param piecesNeeded  The total number of pieces required (k + 1).
     * @param minTarget     The current 'guess' for the minimum sweetness.
     */
    bool canDivide(const std::vector<int>& sweetness, int piecesNeeded, int minTarget) {
        int piecesFound = 0;
        int currentSum = 0;

        for (int s : sweetness) {
            currentSum += s;
            
            // Greedy Step: As soon as the current chunk sum meets the target,
            // we "cut" the piece and start a fresh one.
            if (currentSum >= minTarget) {
                piecesFound++;
                currentSum = 0;
                
                // If we have already found enough pieces, we don't need to
                // process the rest of the array. Return immediately.
                if (piecesFound >= piecesNeeded) return true;
            }
        }
        return false;
    }

public:
    /**
     * Finds the maximum possible value for the minimum sweetness of a piece.
     * Approach: Binary Search on Answer + Greedy Verification.
     *
     * Time Complexity:  O(N * log(TotalSweetness))
     * Space Complexity: O(1)
     */
    int maximizeSweetness(std::vector<int>& sweetness, int k) {
        // We need (k + 1) pieces: one for me, k for my friends.
        int piecesNeeded = k + 1;

        // Use long long for the total sum.
        //
        // Even if individual chunks fit in int, the total sum of 10^4 * 10^5 
        // can approach integer overflow limits (2 billion). 0LL forces 64-bit math.
        long long totalSum = std::accumulate(sweetness.begin(), sweetness.end(), 0LL);
        
        // EDGE CASE: If the total sweetness is 0, we can't get any sweetness.
        if (totalSum == 0) return 0;

        // BINARY SEARCH BOUNDS
        //
        // Low: The smallest possible answer is 1 (constraint: sweetness[i] >= 1).
        // High: The theoretical max is perfect division (Total / Pieces).
        //
        // Using 'average' as high bound significantly tightens the search space compared to 'totalSum'.
        int low = 1;
        int high = (int)(totalSum / piecesNeeded);
        
        int maxSweetness = 0;

        while (low <= high) {
            // Calculate the 'guess' for this iteration.
            int mid = low + (high - low) / 2;

            // Check if this specific sweetness 'mid' is achievable.
            // If mid == 0, it's trivially true (sum >= 0 always works).
            if (mid == 0 || canDivide(sweetness, piecesNeeded, mid)) {
                // SUCCESS: We can achieve 'mid' sweetness!
                //
                // Since we want to MAXIMIZE the minimum, we save this answer 
                // and try to search in the upper half (be greedier).
                maxSweetness = mid;
                low = mid + 1;
            } else {
                // FAILURE: We ran out of chocolate before making k+1 pieces.
                // 'mid' was too high. We must search in the lower half.
                high = mid - 1;
            }
        }
        
        return maxSweetness;
    }
};