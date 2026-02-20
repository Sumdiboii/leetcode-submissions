class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }

        vector<int> s1count(26,0);
        vector<int> s2count(26,0);
        

         int n = s2.length();
         int m = s1.length();

         for(char ch : s1){
            s1count[ ch - 'a']++;
         }

         for( int i = 0; i < m; i++){
            s2count[ s2[i] - 'a']++;

            if(s1count == s2count){
                return true;
            } 
            else{
                continue;
            }
         }

         for(int i = m; i < n; i++){
            s2count[ s2[i] - 'a']++;
            s2count[ s2[i - m] - 'a']--;

            if(s1count==s2count){
                return true;
            }
         }
         return false;

    }
};