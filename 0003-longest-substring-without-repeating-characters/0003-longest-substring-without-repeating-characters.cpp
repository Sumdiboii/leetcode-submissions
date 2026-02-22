class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        int l = 0;
        int subcnt=0;
        int maxsubcnt= 0;

        if(n==1){
            return 1;
        }

        unordered_set<char> uset;

        for(int r = 0; r<n; r++){

            while(uset.count(s[r])){
                uset.erase(s[l]);
                subcnt--;
                l++;
            }

                uset.insert(s[r]);
                subcnt++;

                maxsubcnt = max( maxsubcnt, subcnt);
        }

        return maxsubcnt;
    }
};
