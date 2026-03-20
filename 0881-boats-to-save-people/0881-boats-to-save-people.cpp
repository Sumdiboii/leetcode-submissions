#define all(n) people.begin(), people.end()

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n  = people.size();
        sort(all(n));


        int l = 0; 
        int r =n-1;
        int cnt = 0;

        while( l<=r){
            if( people[l] + people[r] <= limit){
                cnt ++;
                l++;
                r--;
            }
            else if( people[l] + people[r] > limit) {
                cnt ++;
                r--;
            }
            
        }
        return cnt;
    }
};