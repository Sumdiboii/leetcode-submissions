class Solution {
private:
 void solving(vector<vector<int>>& ans,int n,int k,vector<int>& pr,int id){
    if(pr.size()==k){
        ans.push_back(pr);
        return;
    }for(int i=id;i<=n;i++){
        pr.push_back(i);
        solving(ans,n,k,pr,i+1);
        pr.pop_back();
    }
 }    
public:
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> ans;
      vector<int> pr;
      solving(ans,n,k,pr,1);
      return ans;
    }
};