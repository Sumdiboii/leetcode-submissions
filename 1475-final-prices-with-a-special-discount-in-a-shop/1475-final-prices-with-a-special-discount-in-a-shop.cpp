#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> finalPrices(std::vector<int>& prices) {
        std::stack<int> st; // Stores indices of prices
        
        for (int i = 0; i < prices.size(); ++i) {
            // While the stack is not empty and the current price is less than 
            // or equal to the price at the index on top of the stack
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                int indexToDiscount = st.top();
                st.pop();
                prices[indexToDiscount] -= prices[i]; // Apply the discount
            }
            // Push the current index onto the stack
            st.push(i);
        }
        
        return prices;
    }
};