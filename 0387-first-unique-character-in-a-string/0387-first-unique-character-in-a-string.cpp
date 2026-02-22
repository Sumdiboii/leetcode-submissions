class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char,int> umap;

        // Pass 1: count frequency
        for(char c : s){
            umap[c]++;
        }

        // Pass 2: find first unique character
        for(int i = 0; i < s.length(); i++){
            if(umap[s[i]] == 1){
                return i;
            }
        }

        return -1;
    }
};
