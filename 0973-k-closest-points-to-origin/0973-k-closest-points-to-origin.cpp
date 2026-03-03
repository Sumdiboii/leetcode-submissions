class Solution {
public:
int calculateEucdist(int x, int y)
{
     // code for the formula root((x1-x2)^2 + (y1-y2)^2)
     return x*x+y*y;
} 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int n = points.size(); 
        // optimizing it from O(nlogn) to o(nlogk) by max heap of size k
        priority_queue<pair<int, vector<int>>> pq; // max 

        // 1.loop points
        for(auto& point : points)
        {
            int x = point[0];
            int y = point[1];

            int dist = calculateEucdist(x,y);

            //2.keep adding them in max heap, largest top
            pq.push({dist,point});
            
            //3.standard technzique - pop if it goes above k
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        //4.take the ele from heap and answer

        vector<vector<int>> result;
        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};