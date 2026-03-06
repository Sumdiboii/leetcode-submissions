class LRUCache {
private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        // Remove node from linked list
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertToHead(Node* node) {
        // Insert node right after head
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(0,0); // dummy head
        tail = new Node(0,0); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insertToHead(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            remove(node);
            insertToHead(node);
        } else {
            if(cache.size() == capacity) {
                Node* lru = tail->prev;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insertToHead(newNode);
        }
    }

    ~LRUCache() {
        Node* curr = head;
        while(curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};