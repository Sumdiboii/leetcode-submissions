class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset;
        
        vector<int> vect;

        int n = nums1.size();
        int m = nums2.size();

        for( int n : nums1){
            uset.insert(n);
        }
        
        for( int n : nums2){
            if(uset.contains(n)){
            uset.erase(n);
            vect.push_back(n);
            }
            
        }

    return vect;
        
    }
};