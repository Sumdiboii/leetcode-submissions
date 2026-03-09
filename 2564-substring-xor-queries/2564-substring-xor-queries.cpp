class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {

        unordered_map<int, pair<int,int>> mp;
        int n = s.size();

        for(int i = 0; i < n; i++) {

            if(s[i] == '0') {
                if(!mp.count(0))
                    mp[0] = {i,i};
                continue;
            }

            int val = 0;

            for(int j = i; j < min(i+30, n); j++) {
                val = (val << 1) + (s[j]-'0');

                if(!mp.count(val))
                    mp[val] = {i,j};
            }
        }

        vector<vector<int>> ans;

        for(auto &q : queries) {

            int target = q[0] ^ q[1];

            if(mp.count(target))
                ans.push_back({mp[target].first, mp[target].second});
            else
                ans.push_back({-1,-1});
        }

        return ans;
    }
};