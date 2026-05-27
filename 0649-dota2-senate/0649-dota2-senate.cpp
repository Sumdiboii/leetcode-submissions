class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        int a = 0, b = 0;
        int zero = 0;

        while(true) {
            
            for(int i=0; i<n; i++) {
                if(senate[i] == 'R' && b > 0) {
                    senate[i] = '0';
                    zero++;
                    b--;
                } else if(senate[i] == 'R' && b == 0) {
                    a++;
                } else if(senate[i] == 'D' && a > 0) {
                    senate[i] = '0';
                    zero++;
                    a--;
                } else if(senate[i] == 'D' && a == 0) {
                    b++;
                }
            }

            bool aonly = false, bonly = false;

            for(int i=0; i<n; i++) {
                if(senate[i] == 'R') aonly = true;
                else if(senate[i] == 'D') bonly = true;
            }

            if(aonly == true && bonly == false) return "Radiant";
            if(bonly == true && aonly == false) return "Dire";

        }

        return "Dire";
    }
};