class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> aa(26,0);
        

        if(s.length()!= t.length()){
            return false;
        }

        for( char ch : s){
            aa[ch - 'a']++;
        }

         for( char ch : t){
            aa[ch - 'a']--;
        }

         for( int cnt : aa){
            if(cnt != 0){
                return false;
            }
        }

        return true;

    }
};