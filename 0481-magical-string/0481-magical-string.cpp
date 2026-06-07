#include <vector>

class Solution {
public:
    int magicalString(int n) {
        // Handle edge cases
        if (n <= 0) return 0;
        if (n <= 3) return 1;
        
        // Allocate n + 2 to prevent index out-of-bounds 
        // if we append two characters right at the edge of n.
        std::vector<int> magic(n + 2);
        magic[0] = 1; 
        magic[1] = 2; 
        magic[2] = 2;
        
        int head = 2;   // Pointer to read the frequency
        int tail = 3;   // Pointer to write the new characters
        int num = 1;    // The next number to append (since the last was 2)
        int count = 1;  // Counts occurrences of '1' (starting with 1 from the base "122")
        
        // Generate the string until we reach a length of n
        while (tail < n) {
            for (int i = 0; i < magic[head]; ++i) {
                magic[tail] = num;
                
                // Only count '1's that fall within the first n characters
                if (num == 1 && tail < n) {
                    count++;
                }
                tail++;
            }
            
            // Toggle the number to append between 1 and 2
            // If num is 1: 3 - 1 = 2
            // If num is 2: 3 - 2 = 1
            num = 3 - num; 
            
            // Move the reading pointer forward
            head++;
        }
        
        return count;
    }
};