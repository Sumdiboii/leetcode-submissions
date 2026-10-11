class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack<pair<int,int>> stk;


        for( int i = 0; i< n; i++){
            
            while(!stk.empty() && temperatures[i] > stk.top().first){

                auto pair = stk.top();
                stk.pop();
                res[pair.second] = i - pair.second;
            }

            stk.push({temperatures[i], i});
        }

        return res;


    }
};