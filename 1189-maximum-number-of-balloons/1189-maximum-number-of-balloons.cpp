class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char,int> umap;

        // count frequency
        for(char ch : text){
            umap[ch]++;
        }

        // calculate minimum possible balloons
        int result = INT_MAX;

        result = min(result, umap['b']);
        result = min(result, umap['a']);
        result = min(result, umap['l'] / 2);
        result = min(result, umap['o'] / 2);
        result = min(result, umap['n']);

        return result;
    }
};