class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        // Initialize the result vector with the same size as arr
        vector<int> res(n); 
        
        // The last element is always replaced by -1
        int rightmax = -1; 
        
        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {
            res[i] = rightmax;
            rightmax = max(rightmax, arr[i]);
        }
        
        return res;
    }
};
