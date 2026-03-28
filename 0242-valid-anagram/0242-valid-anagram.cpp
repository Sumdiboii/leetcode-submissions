class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.length() != t.length()){
            return false;
        }
        else{
            vector<int> freq1(26,0);
            vector<int> freq2(26,0);

            for( char ch : s){
                freq1[ch - 'a']++;
            }
            for( char ch : t){
                freq2[ch - 'a']++;
            }

           if(freq1 != freq2){
            return false;
           }
        }

        return true;
    }
};