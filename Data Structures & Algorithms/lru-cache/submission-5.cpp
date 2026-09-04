struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};
class LRUCache {
private:
    unordered_map<int, Node*> cache;
    int cap;
    Node* left;
    Node* right;

    void remove(Node* node){
        Node* prev = node->prev;
        prev->next = node->next;
        node->next->prev = prev;
    }

    void insert(Node* node){
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);
        if(cache.size() > cap){
            Node* lru = left->next;
            cache.erase(lru->key);
            remove(lru);
            // delete lru;
        }
    }
};
