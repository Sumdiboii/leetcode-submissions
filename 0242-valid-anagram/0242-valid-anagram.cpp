class Solution {
public:
    bool isAnagram(string s, string t) {
         int n = s.length();
         int m = t.length();

         if( n != m ){
            return false;
         }
         else{

            vector< int> vect(26,0);

            for( char ch : s){
                vect[ch -'a']++;
            }

            
            for( char ch : t){
                vect[ch -'a']--;
            }

            
            for( const auto count  : vect){
                if( count != 0){
                    return false;
                }
            }


         }
         return true;
    }
};