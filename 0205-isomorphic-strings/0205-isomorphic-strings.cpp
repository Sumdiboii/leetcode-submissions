class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();

        unordered_map<char, char> umap1;
        
        unordered_map<char, char> umap2;

        if(n != m){
            return false;
        }

        for( int i = 0; i< n; i++){


            if(umap1.count(s[i]) && umap1[s[i]] != t[i]){
                return false;
            }
            if(umap2.count(t[i]) && umap2[t[i]] != s[i]){
                return false;
            }
            
            umap1[s[i]] = t[i];
            umap2[t[i]] = s[i];

        }

        return true;
    }
};