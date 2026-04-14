static const auto fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define all(x) x.begin(), x.end()

// this solution belong to sumedh pimplikar.. dotnt mind me i am just paranoid ....d 

//eezz question ...very straightforward....lets go 

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {

        
        double a, b, c;
        double aa, bb, cc;
        int sumedh  = 0 ; 
        int pimplikar = INT_MIN;
        // just making sure...
        

        sort(all(sides));

        a = sides[0];
        b = sides[1];
        c = sides[2];

        if(a + b <= c ){
            return {};
        }

        const double pival = acos(-1.0);
        const double converter= 180.0 / pival; /// bro...


        aa = acos(clamp((b*b + c*c - a*a)  / (2.0 * c * b), -1.0, 1.0 )) * converter;
        bb = acos(clamp((a*a + c*c - b*b)  / (2.0 * c * a), -1.0, 1.0 )) * converter;
        cc = acos(clamp((a*a + b*b - c*c)  / (2.0 * a * b), -1.0, 1.0 )) * converter;

        vector<double> res = {aa,bb,cc};

        sort(all(res));

        // ok go it ...lets go !!!

        


        return res;

        // this should work .. lets have a look ...
        

        
    }
};