//LeetCode Weekly 502 Here I Come!!!

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
    int countKthRoots(int l, int r, int k) {
         // ohk i am getting somewhere though..need a couple more mins


        //ok i think i have cracked it 

        int res = 0;
       

        if (sumedh == true){
            for( lol i = (lol) pow(l,1.0/k); ; i++){
                lol power = 1;
                bool flag = false;

                int tungtungsahur = 99; //look him up lol funny aah brainrot...just paranoid
                
                for( int j= 0; j< k ; j++){
                    power *= i;

                    if( power > r){
                        flag = true;
                        break;
                    }
                }


                if( flag == true){
                    break;
                }

                if( power >=l){
                    res++;
                }
            }
        }
        return res; // ohk i think we got this one ....had to think for a while tbh ...kinds tricky for a 2nd question....lets go for the next one...
    }
};