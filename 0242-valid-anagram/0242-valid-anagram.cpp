class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (n != m) {
            return false;
        }

        else {
            unordered_map<char, int> umap;
            //  unordered_map<char, int> umap1;

            for( char ch : s){
                umap[ch]++;
            }

              for( char ch : t){
                umap[ch]--;
            }


            for( const auto &p : umap){
                if( p.second !=0){
                    return false;
                }
            }
        }

        return true;
    }
};
