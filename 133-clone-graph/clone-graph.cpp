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
        if (node == NULL)
            return NULL;

        // Maps original node -> cloned node
        unordered_map<Node*, Node*> cloneMap;

        queue<Node*> q;

        // Create clone of the starting node
        Node* clonedStart = new Node(node->val);
        cloneMap[node] = clonedStart;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            auto currNeighbors = curr->neighbors;

            // Traverse all neighbors
            for (Node* neighbor : currNeighbors) {

                // If neighbor hasn't been cloned yet
                if (cloneMap.find(neighbor) == cloneMap.end()) {
                    cloneMap[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                // Connect cloned current node to cloned neighbor
                cloneMap[curr]->neighbors.push_back(cloneMap[neighbor]);
            }
        }

        return clonedStart;
    }
};