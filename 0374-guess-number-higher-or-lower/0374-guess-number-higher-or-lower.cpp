/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is higher than the picked number
 *               1 if num is lower than the picked number
 *               0 if num is correct
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;

        while(l < r) {               // use < instead of <=
            int mid = l + (r - l) / 2;

            if(guess(mid) <= 0) {    // mid is bad or correct
                r = mid;             // first occurrence is left side including mid
            } else {
                l = mid + 1;         // mid too low, go right
            }
        }

        return l;                    // l == r is the first correct guess
    }
};
