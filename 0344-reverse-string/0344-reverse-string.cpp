#define n s.size()

static const auto fast_io = [](){
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
} ();


class Solution {
public:
    void reverseString(vector<char>& s) {
        int l =0;
        int r = n-1;

        while(l<r) {
            swap (s[l], s[r]);
            l++;
            r--;
        }
    }
};
