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
    Node* head = new Node(-1, -1), *tail = new Node(-1, -1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node){
        Node* nex = node->next;
        Node* pre = node->prev;
        pre->next = nex;
        nex->prev = pre;
    }

    void addNode(Node* node){
        Node* top = head->next;
        head->next = node;
        node->prev = head;
        top->prev = node;
        node->next = top;
    }
    
    int get(int key) {

        if(mpp.find(key) != mpp.end()){
            auto n = mpp[key];
            int v = n->value;
            deleteNode(n);
            addNode(n);
            mpp[key] = n;
            return v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* newNode = new Node(key, value);

        if(mpp.find(key) != mpp.end()){
            auto n = mpp[key];
            mpp.erase(key);
            deleteNode(n);
        }
        else if(mpp.size() == cap){
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