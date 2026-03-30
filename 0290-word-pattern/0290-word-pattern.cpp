class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;

        while(ss >> word){
            words.push_back(word);
        }
        if(words.size() != pattern.size()) return false;
        unordered_map<string,char>mp1;
        unordered_map<char,string>mp2;

        for(int i =0 ;i< words.size();i++){
            if(mp1.count(words[i]) && mp1[words[i]] != pattern[i]) return false;
            if(mp2.count(pattern[i]) && mp2[pattern[i]]!= words[i]) return false;

            mp1[words[i]] = pattern[i];
            mp2[pattern[i]] = words[i];
        }
        return true;
    }
};