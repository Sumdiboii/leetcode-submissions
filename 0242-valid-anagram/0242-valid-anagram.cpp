class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, int> Scount;
        unordered_map<char, int> Tcount;

        for(int i=0; i<s.length(); i++){
            Scount[s[i]]++;
            Tcount[t[i]]++;
        }
        return Scount ==Tcount;
    }
};