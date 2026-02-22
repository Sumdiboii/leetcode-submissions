class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> count;
        int l = 0;
        int maxFruits = 0;

        for(int r = 0; r < fruits.size(); r++) {
            count[fruits[r]]++; // add fruit to window

            // Shrink window if more than 2 types
            while(count.size() > 2) {
                count[fruits[l]]--;
                if(count[fruits[l]] == 0) {
                    count.erase(fruits[l]);
                }
                l++;
            }

            // Update max fruits
            maxFruits = max(maxFruits, r - l + 1);
        }

        return maxFruits;
    }
};