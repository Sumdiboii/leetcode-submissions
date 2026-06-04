#include <vector>
#include <numeric>

class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        int counts[2] = {0, 0};
        
        // Count student preferences
        for (int student : students) {
            counts[student]++;
        }
        
        // Process sandwiches
        for (int sandwich : sandwiches) {
            if (counts[sandwich] > 0) {
                counts[sandwich]--; // A student takes the sandwich
            } else {
                // No students left want this top sandwich; loop terminates
                break;
            }
        }
        
        // The sum of remaining counts is the number of students unable to eat
        return counts[0] + counts[1];
    }
};