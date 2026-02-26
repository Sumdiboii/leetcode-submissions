class Solution {
public:
    int numSteps(string s) {

        int steps = 0;

        while (s != "1") {

            // if even → last bit = 0
            if (s.back() == '0') {
                s.pop_back(); // divide by 2
            }
            else {
                // add 1
                int i = s.size() - 1;

                // handle carry
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }

                if (i >= 0) {
                    s[i] = '1';
                }
                else {
                    s = '1' + s;
                }
            }

            steps++;
        }

        return steps;
    }
};