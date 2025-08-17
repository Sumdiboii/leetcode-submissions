class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length()!=t.length()){
            return false;
        }

        else{
           
           vector<int> vect(26,0);

           for (int i=0; i<s.length();i++){
            vect[s[i]-'a']++;
            vect[t[i]-'a']--;
           }

           for(int val:vect){
            if(val!=0){
                return false;
            }
            
           }
           return true;
        
    }
    }
};