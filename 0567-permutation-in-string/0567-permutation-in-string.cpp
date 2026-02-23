class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if(n>m){
            return 0;
        }
        vector<int> s1vect(26, 0);
        vector<int> s2vect(26, 0);

        for (char ch : s1) {
            s1vect[ch - 'a']++;
        }

        for( int i =0; i<n; i++){
            s2vect[s2[i] - 'a']++;

            if(s1vect==s2vect){
                return true;
            }
        }


         for( int i =n; i<m; i++){
            s2vect[s2[i] - 'a']++;
            s2vect[s2[i-n] - 'a']--;

            if(s1vect==s2vect){
                return true;
            }
        }
        return false;
    }
};