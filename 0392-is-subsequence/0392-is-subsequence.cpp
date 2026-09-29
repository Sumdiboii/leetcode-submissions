class Solution {
public:
    bool isSubsequence(string s, string t) {
        int target = s.length();
        int cnt = 0;

        if( s.length() > t.length()){
            return false;
        }
        else if (s.length() == t.length() && s == t){
            return true;
        }

       
        for( int i = 0 ; i< t.length(); i++){
            if(t[i] == s[cnt]){
                target--;
                cnt++;
            }

            if(target == 0){
                return true;
            }
        }

        return false;

    }
};