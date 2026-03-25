class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        string temp = s + s;

        for( int i = 0; i< n ; i++){
            if(temp.substr(i, n) == goal){
                return true;
            }
        }

        return false;
    }
};