class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> stanS;
        unordered_map<char,int> stanT;

        int n=s.length();

        if(s.length() !=t.length()){
            return false;
        }

        for(int i=0;i<n;i++){
            stanS[s[i]]++;
            stanT[t[i]]++;
        }

        if (stanS==stanT){
            return true;
        }else return false;
    }
};
