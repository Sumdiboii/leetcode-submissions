class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> umap;

        for (char ch : s) {
            umap[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto &p : umap) {
            pq.push({p.second, p.first});
        }

        string res = "";

        while (!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            res.append(freq, ch);  
        }

        return res;
    }
};