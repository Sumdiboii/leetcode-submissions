class Solution {
public:
    string minRemoveToMakeValid(string s) {

        string temp;
        int open = 0;

        // First pass: remove invalid ')'
        for(char c : s) {
            if(c == '(') {
                open++;
                temp.push_back(c);
            }
            else if(c == ')') {
                if(open > 0) {
                    open--;
                    temp.push_back(c);
                }
            }
            else {
                temp.push_back(c);
            }
        }

        string ans;

        // Second pass: remove extra '('
        for(int i = temp.size() - 1; i >= 0; i--) {
            if(temp[i] == '(' && open > 0) {
                open--;
                continue;
            }
            ans.push_back(temp[i]);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};