class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> seen;   // to detect cycles

        while (n != 1) {

            if (seen.count(n))   // cycle detected
                return false;

            seen.insert(n);

            int sum = 0;   // reset sum every cycle

            while (n > 0) {
                int digit = n % 10;
                n = n / 10;
                sum += digit * digit;
            }

            n = sum;   // new number
        }

        return true;
    }
};
