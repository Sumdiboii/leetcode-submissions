class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
     int five = 0; // Counter for $5 bills
        int ten = 0;  // Counter for $10 bills

        // Process each customer's bill
        for (int bill : bills) {
            if (bill == 5) {
                // Customer pays with $5 -> no change needed
                five++;
            }
            else if (bill == 10) {
                // Customer pays with $10 -> needs $5 as change
                if (five > 0) {
                    five--; // Give one $5 as change
                    ten++;  // Accept the $10 bill
                } else {
                    return false; // Cannot provide change
                }
            }
            else { // bill == 20
                // Customer pays with $20 -> needs $15 as change
                if (five > 0 && ten > 0) {
                    five--; // Use one $5
                    ten--;  // Use one $10
                } 
                else if (five >= 3) {
                    five -= 3; // Use three $5 bills
                } 
                else {
                    return false; // Cannot provide change
                }
            }
        }
        return true; // Successfully gave change to all customers
    }
};