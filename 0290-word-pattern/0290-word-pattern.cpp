class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss>>word){
            words.push_back(word);
        }

        unordered_map<char, string> umap1;
        unordered_map<string, char> umap2;

        int n = pattern.size();
        int m = words.size();

        if(n != m ){
            return false;
        }

       

        for( int i = 0; i< n ; i++){

            if(umap1.count(pattern[i]) && umap1[pattern[i]] != words[i]){
                return false;
            }

            if(umap2.count(words[i]) && umap2[words[i]] != pattern[i]){
                return false;
            }
            umap1[pattern[i]] = words[i];
            
            umap2[words[i]] = pattern[i];
        }
        return true;
    }
};