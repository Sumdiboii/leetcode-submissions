class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        
            if((n & ((n-1)))==0){
                int pos = __builtin_ctz(n);

                if(pos & 1){
                    return false;
                }
                else{
                    return true;
                }
            }
        return false;
    }
};