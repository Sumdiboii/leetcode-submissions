class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    
    int n = nums2.size();
    vector<int> ans(n, -1);
    stack<int> st;   // stores indices
    
    // ===== TEMPLATE START =====
    for(int i = 0; i < n; i++) {
        
        while(!st.empty() && nums2[st.top()] < nums2[i]) {
            ans[st.top()] = nums2[i];
            st.pop();
        }
        
        st.push(i);
    }
    // ===== TEMPLATE END =====
    
    // Step 2: Map values -> next greater
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++) {
        mp[nums2[i]] = ans[i];
    }
    
    // Step 3: Answer nums1 queries
    vector<int> result;
    for(int num : nums1) {
        result.push_back(mp[num]);
    }
    
    return result;
}
};