class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, unordered_set<int>> mp;
        
        for(auto &seat : reservedSeats)
            mp[seat[0]].insert(seat[1]);
        
        int ans = (n - mp.size()) * 2;
        
        for(auto &row : mp){
            
            auto &s = row.second;
            
            bool left = !(s.count(2) || s.count(3) || s.count(4) || s.count(5));
            bool right = !(s.count(6) || s.count(7) || s.count(8) || s.count(9));
            bool middle = !(s.count(4) || s.count(5) || s.count(6) || s.count(7));
            
            if(left && right)
                ans += 2;
            else if(left || right || middle)
                ans += 1;
        }
        
        return ans;
    }
};