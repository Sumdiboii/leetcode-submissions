class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m =matrix.size();
        int n= matrix[0].size();

       int s=0,c=n-1;
       while(s<m && c>=0){
        if(matrix[s][c]== target){
            return true;
        }
        matrix[s][c]>target ? c--:s++;
       }
        return false;
    }
};