class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length()!=t.length()){
            cerr<<"invalid"<<endl;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s==t){
            return true;
        }
        else{
            return false;
        }
    }
};