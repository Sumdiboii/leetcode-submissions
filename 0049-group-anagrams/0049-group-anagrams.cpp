class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> umap;

        for (string s : strs) {

            vector<int> freq(26, 0);
            for (char ch : s) {
                

                freq[ ch - 'a']++;

            }

            string key = "";

            for( int count : freq){
                key+= to_string(count) + "brev";
            }

            umap[key].push_back(s);
        }

        vector<vector<string>> vect;

        for( auto & p : umap){
            vect.push_back(p.second);
        }

        return vect;




    }
};