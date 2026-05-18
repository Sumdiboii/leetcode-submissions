static const auto fast_io =[](){
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
return 0;
}();

#define all(x) x.begin(), x.end()
#define pbs push_back
#define f first
#define s second

// this code belongs to Sumedh Pimplikar and is my official submission towards this contest problem statement

//I am a bit paranoid so don't mind me...

static bool sumedh = true;

class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {

        int baba = 67; //just paranoid

        if(sumedh != true){
            return {};
        }


        int n = nums.size();
        vector<int> res(n);
        vector<int> fres;

        long long l;
        long long r;

        long long cf;
        long long cb;


        vector<long long> pf(n,0);

        vector<long long> pb(n,0);


        for( int i = 0; i< n; i++){

            if( i == 0){
                res[i] = 1;
            }
            else if(i == n-1){
                res[i] = n-2;
            }
            else{
                l = nums[i] - nums[i-1];
                r = nums[i+1]- nums[i];

                if(r<l){
                    res[i] = i+1;
                }
                else{
                    res[i] = i-1;
                }
            }
        }

            for( int i = 0; i< n-1; i++)
            {
                cf = (res[i] == i+1) ? 1 : (long long)nums[i +1] - nums[i];
                pf[i+1] = pf[i] + cf;
            }

            for( int i = n-1; i>0; i--)
            {
                cb = (res[i] == i-1) ? 1 : (long long )nums[i] - nums[i-1];
                 pb[i-1] = pb[i] + cb;

            }

            for( const auto &p : queries){
                int a = p[0];
                int b = p[1];
                if( a<= b){
                    fres.pbs((int)(pf[b] - pf[a]));
                }else{
                     fres.pbs((int)(pb[b] - pb[a]));
                }
            }

            


            //ok i got this one too...lets see if we canhave a good 4th question...hopefully

        // ok lets go  for the next 
        

        return fres;
    }
};