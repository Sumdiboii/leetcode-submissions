class MyHashMap {
public:
    MyHashMap() {
        _map.fill(-1);
    }

    int hash(int key) {
       return key % 100000;
    }
    
    void put(int key, int value) {
        _map[hash(key)] = value;
    }
    
    int get(int key) {
        return _map[hash(key)] == -1 ? -1 : _map[hash(key)];
    }
    
    void remove(int key) {
        _map[hash(key)] = -1;
    }
private:
    array<int, 100000> _map;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */