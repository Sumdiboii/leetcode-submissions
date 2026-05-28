class Solution {
public:
    int numTrees(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++)
            result *= 4 - 6.0 / (i + 1);
        return result; 
    }
};