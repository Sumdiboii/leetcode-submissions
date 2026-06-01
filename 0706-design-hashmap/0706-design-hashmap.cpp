class MyHashMap {
public:
    int n = 10000;
    vector<vector<pair<int,int>>> arr;

    MyHashMap() {
        arr.resize(n);  
    }

    void put(int key, int value) {
        int idx = key % n;
        for (auto &[a, b] : arr[idx]) {
            if (a == key) {
                b = value;
                return;
            }
        }
        arr[idx].push_back({key, value});
    }

    int get(int key) {
        int idx = key % n;
        for (auto &[a, b] : arr[idx]) {
            if (a == key) return b;
        }
        return -1;
    }

    void remove(int key) {
        int idx = key % n;
        for (int i = 0; i < arr[idx].size(); i++) {
            if (arr[idx][i].first == key) {
                arr[idx].erase(arr[idx].begin() + i);
                return;
            }
        }
    }
};