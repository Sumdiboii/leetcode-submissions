class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total_waviness = 0;
        
        for (int num = num1; num <= num2; ++num) {
            // A number needs at least 3 digits to have a peak or valley
            if (num < 100) {
                continue; 
            }
                
            int temp = num;
            
            // Extract the first two digits from the right
            int right_digit = temp % 10;
            temp /= 10;
            int mid_digit = temp % 10;
            temp /= 10;
            
            // Slide the window through the rest of the number
            while (temp > 0) {
                int left_digit = temp % 10;
                
                // Check for Peak: left < mid > right
                // Check for Valley: left > mid < right
                if ((left_digit < mid_digit && mid_digit > right_digit) || 
                    (left_digit > mid_digit && mid_digit < right_digit)) {
                    total_waviness++;
                }
                    
                // Shift the window to the left
                right_digit = mid_digit;
                mid_digit = left_digit;
                temp /= 10;
            }
        }
        
        return total_waviness;
    }
};