class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        vector<int> digits;
        int temp = x;

        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }

        int left = 0, right = digits.size() - 1;

        while (left < right) {
            if (digits[left] != digits[right]) return false;
            left++;
            right--;
        }

        return true;
    }
};
