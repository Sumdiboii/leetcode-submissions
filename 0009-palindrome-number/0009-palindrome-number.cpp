class Solution {
public:
    bool isPalindrome(int y) {

int x = y;

int rem = 0;
long long rev = 0;
if( x < 0){
    return false;
}

while(x !=0){
    rem  = x%10;
    // if(rev =< INT_MIN || rev >= INT_MAX){
    //     return false;
    // }
    rev = rev * 10 + rem;
    x= x/10;
}

if (rev == y)
{
    return true;
}
return false;

    }
};
