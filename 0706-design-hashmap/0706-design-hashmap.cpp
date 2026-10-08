#include <vector>

class MyHashMap {
public:
    // Initialize the vector with a size large enough to handle the constraints
    // LeetCode constraints for key/value are usually up to 1,000,000.
    MyHashMap() {
        _map.assign(1000001, -1);
    }
    
    // Maps the key directly to its index
    void put(int key, int value) {
        _map[key] = value;
    }
    
    // Returns the value to which the specified key is mapped, or -1 if it contains no mapping
    int get(int key) {
        return _map[key];
    }
    
    // Removes the mapping for the numerical key by setting it back to -1
    void remove(int key) {
        _map[key] = -1;
    }

private:
    std::vector<int> _map;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
