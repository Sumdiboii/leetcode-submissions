class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        
        for (const string& str : details) {
            // Subtract '0' to convert char to int
            int digit2 = str[11] - '0'; // Tens digit (12th character)
            int digit1 = str[12] - '0'; // Ones digit (13th character)
            
            int num = digit2 * 10 + digit1;
            
            if (num > 60) { // "Strictly more than 60 years old" means >= 61
                cnt++;
            }
        }
        return cnt;
    }
};
