class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        int n = s1.length();
        int m = s2.length();
        int window = 0;

        if(n > m){
            return false;
        }

        for( char ch : s1){
            freq1[ch - 'a']++;
        }

        int l = 0;

        for(int r = 0; r<m; r++){

            freq2[s2[r] - 'a']++;

            window = r - l + 1;  
            
            if(window > n){
                 freq2[s2[l] - 'a']--;
                l++;
            }

            if(freq1 == freq2){
                return true;
            }


           
        }


        return false;
    }
};