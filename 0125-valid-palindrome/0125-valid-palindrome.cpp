class Solution {
public:
    bool isPalindrome(string s) {
stringstream ss (s);
string word = "";
        string result = "";

        while( ss>>word){
            for(char ch : word){
                if(isalnum(ch)){
                    result += tolower(ch);
                }
            }
        }
string result2 = result;

        reverse(result.begin(), result.end());

        if( result == result2){
            return true;
        }
        else return false;

        



        




    }
};
