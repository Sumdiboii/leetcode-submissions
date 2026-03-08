class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int n = reader.length();
        int l = 0, r = n-1;
        while (l < r) {
            int mid = l + (r-l)/2;
            if ((r-l) % 2 == 0) {
                int result = reader.compareSub(l, mid-1, mid+1, r);
                if (result == 0) return mid;
                else if (result == 1) {r = mid-1;}
                else                  {l = mid+1;}
            } else {
                int result = reader.compareSub(l, mid, mid+1, r);
                if (result == 1) {r = mid;}
                else             {l = mid+1;}
            }
        }
        return l;

    }
};