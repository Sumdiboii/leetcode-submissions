class Solution {
private:
    int dp[301];
    bool find(int ind, string &s, unordered_set<string>& st){
        if(ind==s.size())return true;

        if(dp[ind]!=-1)return dp[ind];

        bool ans=false;
        for(int i=ind;i<s.size();i++){
            if(st.count(s.substr(ind,i-ind+1)))ans|=find(i+1,s,st);
            if(ans)return true;
        }
        return dp[ind]=ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        memset(dp,-1,sizeof(dp));
        return find(0,s,st);
    }
};