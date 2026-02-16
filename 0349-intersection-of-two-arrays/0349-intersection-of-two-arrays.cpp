class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a;
        unordered_set<int> b;
        
        for( int i : nums1){
            a.insert(i);
        }

        for( int i : nums2){
            if(a.count(i)){
                b.insert(i);
            }
        }

        vector<int> result;
        for(int i : b){
            result.push_back(i);
        }
        return result;
         
    }
};