static const auto fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

class Solution {
public:
    string reverseStr(string s, int k) {

        int n = s.length();

        for(int i = 0; i < n; i += 2*k){

            int l = i;
            int r = min(i + k - 1, n - 1);

            while(l < r){
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }

        return s;
    }
};