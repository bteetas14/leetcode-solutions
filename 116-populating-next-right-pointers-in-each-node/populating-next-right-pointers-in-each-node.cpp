/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<pair<Node*, pair<int, int>>> q;
        if(root==NULL) return root;
        // node level column

        map<int, vector<pair<int, Node*>>> mpp;
        q.push({root, {0, 0}});

        while(!q.empty()){
            Node* node = q.front().first;
            auto [level, col] = q.front().second;
            q.pop();

            mpp[level].push_back({col, node});
            
            if(node->left != nullptr){
                q.push({node->left, {level+1, col-1}});
            }
            if(node->right != nullptr){
                q.push({node->right, {level+1, col+1}});
            }
        }

        for(auto it:mpp){
            auto &v = it.second;

            for(int i=0;i<v.size()-1;i++){
                v[i].second->next = v[i+1].second;
            }
        }
        return root;
    }
};