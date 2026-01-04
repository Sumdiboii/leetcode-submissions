class Solution {
public:
    bool isPalindrome(string s) {
        string news="";
        for(char c:s){
            if(isalnum(c)){
                news += tolower(c);
            }
        }
        string rev=string(news.rbegin(), news.rend());

        if(news==rev){
            return true;
        }
        else return false;
    }
};
