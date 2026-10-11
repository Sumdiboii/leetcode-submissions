class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> stk;


        for( const string& s : tokens){


            if( n > 2 && s == "+"){
                int val1 = stk.top();
                stk.pop();

                int val2 = stk.top();
                stk.pop();

                stk.push(val1 + val2);
            }
            else if ( n > 2 && s == "*"){
                 int val1 = stk.top();
                stk.pop();

                int val2 = stk.top();
                stk.pop();

                stk.push(val1 * val2);
            }
            else if (n > 2 && s == "-") {
                 int val1 = stk.top();
                stk.pop();

                int val2 = stk.top();
                stk.pop();

                stk.push(val2 - val1);
            }else if (n > 2 && s == "/") {
                 int val1 = stk.top();
                stk.pop();

                int val2 = stk.top();
                stk.pop();

                stk.push(val2 / val1);
            }else{
                stk.push(stoi(s));
            }
        }

        return stk.top();
    }
};