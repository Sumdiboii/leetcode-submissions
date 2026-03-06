class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        
        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        
        // Step 2: Merge overlapping intervals
        for(int i = 1; i < intervals.size(); i++) {
            if(merged.back()[1] < intervals[i][0]) {
                // No overlap, just add interval
                merged.push_back(intervals[i]);
            } else {
                // Overlap exists, merge
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
        }
        
        return merged;
    }
};