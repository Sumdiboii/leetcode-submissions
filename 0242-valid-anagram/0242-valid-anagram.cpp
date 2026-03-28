class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.length() != t.length()){
            return false;
        }
        else{
            vector<int> freq(26,0);

            for( char ch : s){
                freq[ch - 'a']++;
            }
            for( char ch : t){
                freq[ch - 'a']--;
            }

            for( int i : freq){
                if(i != 0){
                    return false;
                }
            }
        }

        return true;
    }
};