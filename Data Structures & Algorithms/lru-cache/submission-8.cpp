#include <mutex>
struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int val): key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    mutable mutex m;

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
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        lock_guard<mutex> guard(m);
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        lock_guard<mutex> guard(m);
        if(cache.find(key) != cache.end()){
            cache[key]->val = value;
            remove(cache[key]);
            insert(cache[key]);
            return;
        }

        Node* newNode = new Node(key, value);
        insert(newNode);
        cache[key] = newNode;
        if(cache.size() > cap){
            Node* lru = left->next;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
        }
    }
};
