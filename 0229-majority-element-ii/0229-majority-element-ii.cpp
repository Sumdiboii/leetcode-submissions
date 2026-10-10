#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = INT_MIN, candidate2 = INT_MIN;
        int count1 = 0, count2 = 0;

        // Pass 1: Find candidates
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Pass 2: Verify candidates
        int actualCount1 = 0;
        int actualCount2 = 0;


for (int num : nums) {
    if (count1 > 0 && num == candidate1) actualCount1++;
    if (count2 > 0 && num == candidate2) actualCount2++;
}

// Verification: Only actualCount > threshold is necessary
vector<int> result;
int threshold = nums.size() / 3;

if (actualCount1 > threshold) {
    result.push_back(candidate1);
}
if (actualCount2 > threshold) {
    result.push_back(candidate2);
}

        return result;
    }
};