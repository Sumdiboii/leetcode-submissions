class Solution {
public:
    string reverseWords(string s) {
     stringstream sss(s);
     string word;
     string res = "";

     while(sss>>word){
        res = word + " " + res;

     }   

     if( !res.empty()){
        res.pop_back();
     }

     return res;
    }
};