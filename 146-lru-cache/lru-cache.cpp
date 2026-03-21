class LRUCache {
public:
    struct Node{
        int key, value;
        Node *prev, *next;
        Node(int k, int v){
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int cap;
    unordered_map<int, Node*> mpp;
    Node *head = new Node(-1, -1), *tail = new Node(-1, -1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node){
        Node* nex = head->next;
        head->next = node;
        node->next = nex;
        node->prev = head;
        nex->prev = node;
    }

    void deleteNode(Node* node){
        Node* nex = node->next;
        Node* pre = node->prev;
        pre->next = nex;
        nex->prev = pre;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            Node* n = mpp[key];
            int val = n->value;
            mpp.erase(key);
            deleteNode(n);
            addNode(n);
            mpp[key] = head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* newNode = new Node(key, value);
        if(mpp.find(key)!=mpp.end()){
            Node* n = mpp[key];
            mpp.erase(key);
            deleteNode(n);
        }
        else if(mpp.size()==cap){
            Node* last = tail->prev;
            deleteNode(last);
            mpp.erase(last->key);
        }
        addNode(newNode);
        mpp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */