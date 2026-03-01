class Solution {
public:
    string trimTrailingVowels(string s) {
        string ans = "";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] == 'o'|| s[i] == 'u'){
                continue;
            }else{
                while(i >= 0){
                    ans += s[i];
                    i--;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};