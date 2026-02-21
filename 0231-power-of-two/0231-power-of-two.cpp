class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;          // negative numbers and 0 are never powers of two
        return (n & (n - 1)) == 0;         // classic bit trick
    }
};