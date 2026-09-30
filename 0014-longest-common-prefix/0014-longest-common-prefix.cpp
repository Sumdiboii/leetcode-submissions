class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();

        if(n == 0){
            return "";
        }


        string res = "";

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string second = strs[n-1];

        int lmt = min(first.size(), second.size());

        for( int i = 0; i<lmt;i++){
            if(first[i] == second[i]){
                res += first[i];
            }else{
                break;
            }
        }
return res;


    }
};