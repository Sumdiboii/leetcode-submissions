class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        int idx = 13;

        int num = 0;

        for (string str : details) {

            int digit1 = str[12] - '0';
            int digit2 = str[11] - '0';

            num = digit2 * 10 + digit1;

            if (num >= 61) {
                cnt++;
                continue;
            }
        }

        return cnt;
    }
};