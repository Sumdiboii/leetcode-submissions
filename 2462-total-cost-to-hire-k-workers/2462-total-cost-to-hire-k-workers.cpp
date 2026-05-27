class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        auto lambda = [&](const pair<int,int>& p1, const pair<int,int>& p2){
            if(p1.first == p2.first) return p1.second > p2.second;
            return p1.first > p2.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(lambda)>min_heap(lambda);

        int l,r;
        bool flag=false;

        for(l=0 ; l<candidates ; l++){
            min_heap.push({costs[l], l});
        }


        for(r=costs.size()-1 ; r>=costs.size()-candidates ; r--){
            if(r < l){
                flag = true;
                break;
            }
            min_heap.push({costs[r], r});
        }

        long long total = 0;

        while(k--){
            auto temp = min_heap.top();
            min_heap.pop();
            total+=temp.first;
            if(flag){
                continue;
            }
            if(temp.second < l){
                min_heap.push({costs[l], l});
                l++;
            }else{
                min_heap.push({costs[r], r});
                r--;
            }
            if(l>r){
                flag = true;
            }
        }

        return total;

    }
};