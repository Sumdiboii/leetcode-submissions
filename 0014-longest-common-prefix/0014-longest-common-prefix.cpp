class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        int n = strs.size();

        if( n == 0){
            return "";
        }else if(n==1 ){
            return strs[0];
        }

        string first = strs[0];
        string second = strs[n-1];

        int m = first.size();
        int x = second.size();

        string res = "";

        for(int i = 0; i< min(m, x); i++){
            if(first[i] == second[i]){
               
                res.push_back(first[i]);
            }
            else{
                return res;
            }
        }

        return res;
    }
};