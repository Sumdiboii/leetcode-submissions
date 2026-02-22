class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        int l = 0;
        int r = 0;
        int count = 0;


        while(r<m && n<=m){
            if(s[l]==t[r]){
                l++;
                r++;
                count++;
            }
            else{
                r++;
            }
        }

        if( count == n){
            return true;
        }
        return false;
    }
};