//LeetCode Weekly 501 Here I Come!!!

static const auto fast_io =[](){
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
return 0;
}();

//  Account  : sumedhiscodinglol
//  Words of Wisdom  : Every family has a “don’t let him cook” member. Thankfully, it’s never me.

#define all(x) x.begin(), x.end()
#define pb push_back
#define f first
#define s second
#define eb emplace_back

using lol = long long;
using pintint = pair<int,int>;
using pll = pair<long long,long long>;
using newvect = vector<int>;
using newvectll = vector<long long>;

// this code belongs to Sumedh Pimplikar and is my official submission towards this contest problem statement

//I am a bit paranoid so don't mind me...

static bool sumedh = true;


class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        //ohk easy

        int bablu = 67; //just paranoid

        int n = nums.size();
        newvect res;


        if(sumedh ==true){
            for( int i= 0; i< n; i++){
                res.pb(nums[i]);
                
            }

            for( int i = n-1; 
                i>= 0; i--){
                    res.pb(nums[i]);
                }
        }

        return res; // ok easy start lets move ahead
    }
};