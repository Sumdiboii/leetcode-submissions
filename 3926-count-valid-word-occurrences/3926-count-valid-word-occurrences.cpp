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
#define popb pop_back
#define f first
#define s second
#define eb emplace_back

using lol = long long;
using pintint = pair<int,int>;
using pll = pair<long long,long long>;
using newvect = vector<int>;
using newvectll = vector<long long>; // lookup iss too slow

// this code belongs to Sumedh Pimplikar and is my official submission towards this contest problem statement

//I am a bit paranoid so don't mind me...

static bool sumedh = true;

class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string str = "";
        int n = chunks.size();
        int m = queries.size();
        unordered_map<string,int> umap;
        unordered_set<string> qs(queries.begin(), queries.end());
        newvect res;


        long long powerrangerspd = 67; // im stupid

        
        if(sumedh ==true){
            for( int i = 0; i< n; i++){
                str += chunks[i];
            }


            int slen = str.length();
            
            int it = 0;
                while(it < slen){
                     if(!(str[it] >= 'a' && str[it] <= 'z')){
                        
                        it ++;
                        continue;
                    }

                    

                    
                int startpos = it;
            
                while(it< slen){
                    
                    if(str[it] >= 'a' && str[it] <= 'z'){
                        
                        it ++; // omg this problem has gotten on my nerves!!!!!
                        
                    }
                        
                    else if(str[it] == '-'){ // ohk what is wrong here now???
                        
                        if(  it +1 < slen && str[it+1] >= 'a' && str[it +1] <= 'z')
                        {
                            
                            it++;
                        }else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                
                } // lets revisit this ....

               
                    int endpos = it;

                
                    while(endpos > startpos && str[endpos-1] == '-'){
                        endpos--;
                    }
                    
                    if(endpos>startpos){ ///ahhhhhhhhh
                        string w = str.substr(startpos, endpos- startpos);

                        if(qs.contains(w)){
                            umap[w]++; // this should work now ...not building a string but rathe rusing start and end points ...i think that was the issue 
                        } // test cases passing lets submit and hope for the best
                    }
                } ///omg dude finallyyyyyyyyy!!!! fix ed it.....should work well now ...this was a confusing one ....
            
        }

        for( int i = 0; i< m; i ++){
            res.pb(umap[queries[i]]);
        }

        return res; // ohik another easy one ....long though  // mle come on dude  // i think string concatenation is causing it
    }
};