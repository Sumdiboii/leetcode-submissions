class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n  = s.length();
        int m = p.length();

        vector<int> pcnt(26,0);
        vector<int> scnt(26,0);
        vector<int> res;

        for( char ch : p){
            pcnt[ch - 'a']++;
        }

        if(m > n){
            return {};
        }

        for( int i = 0; i< m; i++){
             scnt[s[i] - 'a']++;
        }

        if(scnt == pcnt){
            res.push_back(0);
        }

        for( int i = m; i< n; i++){
             scnt[s[i] - 'a']++;
             scnt[s[i-m] - 'a']--;

             if(pcnt ==scnt){
                res.push_back(i-m+1);
             }
        }

        return res;
    }
};