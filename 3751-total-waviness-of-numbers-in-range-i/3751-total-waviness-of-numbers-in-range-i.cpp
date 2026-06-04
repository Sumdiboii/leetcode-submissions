class Solution {
public:
    int count(string s){
        int n = s.size();
        int i = 0;
        int cnt = 0;
        while(i<n){
            if(i-1>=0 && i+1<n && s[i]>s[i-1] && s[i]>s[i+1]){
                cnt++;
            }
            if(i-1>=0 && i+1<n && s[i]<s[i-1] && s[i]<s[i+1]){
                cnt++;
            }
            i++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int sum = 0;
        for(int i = num1;i<=num2;i++){
            sum += count(to_string(i));
        }
        return sum;
    }
};