class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int n = matrix.size();
        int m = matrix[0].size();

        // 1. FIRST BINARY SEARCH: Find the correct row
        int top = 0;
        int bot = n - 1;
        int target_row = -1;

        while (top <= bot) {
            int mid_row = top + (bot - top) / 2;

            // Check if target falls within the range of this row
            if (target >= matrix[mid_row][0] && target <= matrix[mid_row][m - 1]) {
                target_row = mid_row;
                break; // Found the correct row!
            }
            else if (target < matrix[mid_row][0]) {
                bot = mid_row - 1; // Target is in an earlier row
            }
            else {
                top = mid_row + 1; // Target is in a later row
            }
        }

        // If we didn't find a valid row, the target isn't in the matrix
        if (target_row == -1) return false;

        // 2. SECOND BINARY SEARCH: Search within that specific row
        int l = 0;
        int r = m - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (matrix[target_row][mid] == target) {
                return true;
            } else if (matrix[target_row][mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};
