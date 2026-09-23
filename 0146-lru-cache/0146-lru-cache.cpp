class LRUCache {
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    
    // Helper function to remove an existing node from the linked list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    // Helper function to insert a node right after the dummy head
    void addNodeToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        Node* node = cache[key];
        // Move the accessed node to the front (most recently used)
        removeNode(node);
        addNodeToHead(node);
        
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Node exists: update value and move to front
            Node* node = cache[key];
            node->val = value;
            removeNode(node);
            addNodeToHead(node);
        } else {
            // Node doesn't exist: check capacity before adding
            if (cache.size() == capacity) {
                // Evict the least recently used node (right before tail)
                Node* lru = tail->prev;
                cache.erase(lru->key);
                removeNode(lru);
                delete lru; // Free memory
            }
            
            // Add the new node to the front
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNodeToHead(newNode);
        }
    }
};