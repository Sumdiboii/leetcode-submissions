class MyHashSet {
    vector<bool> res;
public:
    MyHashSet() : res(1000001, false) {}
    
    void add(int key) {
        res[key] = true;
    }
    
    void remove(int key) {
        res[key] = false;
    }
    
    bool contains(int key) {
        return res[key];
    }
};
