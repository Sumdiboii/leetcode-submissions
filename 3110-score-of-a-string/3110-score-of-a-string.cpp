class Solution {
public:
    int scoreOfString(string s) {
        int n = s.length();

        int runsum = 0;


        for( int i = 0; i< n-1; i++){
            runsum += abs(s[i] - s[i+1]);
        }
return runsum;

    }
};