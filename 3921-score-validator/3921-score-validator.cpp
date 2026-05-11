//LeetCode BiWeekly 182 Here I Come!!!

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
    vector<int> scoreValidator(vector<string>& events) {
        int sc = 0; 
        int cntr = 0;
        newvect res;
        long long baba = 6767; // just paranoid...easy btw

        if( sumedh ==true){
            for( const auto& p : events){
                if(cntr >=10){
                    break;
                }

                if(p == "W"){
                    cntr++;
                }
                else if (p == "WD"){
                    sc++;
                }
                else if( p == "NB"){
                    sc++;
                }
                else{
                    sc = sc + stoi(p);
                }


                if(cntr >= 10){
                    break;
                }
            }
        }


        res = {sc, cntr};

        return res;

        // ok this one was pretty easy ....just made a new coding template ....kinda like it ...lets move to the next question
    }
};