/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node == nullptr) return nullptr;

        unordered_map<Node*, Node*> mpp;
        queue<Node*> q;

        Node* clonedNew = new Node(node->val);
        mpp[node] = clonedNew;
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            auto neighbors = curr->neighbors;

            for(auto it:neighbors){
                if(mpp.find(it)==mpp.end()){
                    mpp[it] = new Node(it->val);
                    q.push(it);
                }

                mpp[curr]->neighbors.push_back(mpp[it]);
            }
        }
        return clonedNew;
    }
};