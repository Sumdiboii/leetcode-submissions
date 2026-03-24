class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int r = n;
        int c = matrix[0].size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for( int i = 0 ; i < c; i++){
            for( int j = 0; j< r; j++){
                pq.push(matrix[i][j]);
            }
        }

        int res = 0;


        while(k != 0){
            res = pq.top();
            pq.pop();
            k--;
        }

        return res;
    }
};