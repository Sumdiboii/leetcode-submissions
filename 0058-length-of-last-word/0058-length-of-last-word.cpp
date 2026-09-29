class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();

        // int ptr = n;
        int i = n-1;
        int cnt = 0;

        if(s.empty()){
            return 0;
        }

        while(i>= 0 && !isalpha(s[i])){
           i--;
        }


        while(i >= 0){

            if(!isalpha(s[i])){
                break;
            }

            cnt++;
            i--;
            

        }

        return cnt;
    }
};