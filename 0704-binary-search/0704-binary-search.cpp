class Solution { 
public: 
    int search(vector<int>& nums, int target) { 
        int n = nums.size(); 
        int l = 0; 
        int r = n - 1; 
        
        while (l <= r) { 
            // 1. Corrected overflow-safe mid calculation
            int m = l + (r - l) / 2; 
            
            if (nums[m] > target) { 
                r = m - 1; 
            } else if (nums[m] == target) { 
                return m; 
            } else { 
                // 2. Fixed infinite loop by narrowing search space
                l = m + 1; 
            } 
        } 
        // 3. Fixed return type syntax
        return -1; 
    } 
};
