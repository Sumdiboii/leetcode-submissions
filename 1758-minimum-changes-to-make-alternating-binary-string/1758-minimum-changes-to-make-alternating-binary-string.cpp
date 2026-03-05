#include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int countStart0 = 0; // Changes if pattern starts with '0'
        int countStart1 = 0; // Changes if pattern starts with '1'
        
        for (int i = 0; i < s.size(); i++) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';
            
            if (s[i] != expected0) countStart0++;
            if (s[i] != expected1) countStart1++;
        }
        
        return min(countStart0, countStart1);
    }
};