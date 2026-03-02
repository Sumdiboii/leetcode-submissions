class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int heaviestStone = 0;
        int secondHeaviestStone = 0;
        priority_queue<int> p;
        for (int i = 0; i < stones.size(); i++)
            p.push(stones[i]);

        while (p.size() > 1) {
            heaviestStone = p.top();
            p.pop();
            secondHeaviestStone = p.top();
            p.pop();
            p.push(heaviestStone - secondHeaviestStone);
        }
        if (p.empty())
            return 0;
        return p.top();
    }
};