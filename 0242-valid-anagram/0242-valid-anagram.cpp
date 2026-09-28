class Solution {
public:
    bool isAnagram(string s, string t) {
        // int n = s.length();
        // int m = t.length();

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // if(s ==t){
        //     return true;
        // }
        // return false;

        unordered_map<char, int> umap;

        for(char ch : s){
            umap[ch - 'a']++;
        }

        for(char ch : t){
            umap[ch - 'a']--;
        }


        for( const auto& it : umap){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};