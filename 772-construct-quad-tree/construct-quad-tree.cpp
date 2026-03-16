/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool allCellSame(int row, int col, int n, vector<vector<int>>&grid){
        int org = grid[row][col];
        for(int i=row;i<row+n;i++){
            for(int j=col;j<col+n;j++){
                if(grid[i][j] != org){
                    return false;
                }
            }
        }
        return true;
    }

    Node* solve(int row, int col, int n, vector<vector<int>>& grid){

        if(allCellSame(row, col, n, grid)){
            return new Node(grid[row][col], true, NULL, NULL, NULL, NULL);
        }

        Node* topLeft = solve(row, col, n/2, grid);
        Node* topRight = solve(row, col + n/2, n/2, grid);
        Node* bottomLeft = solve(row + n/2, col, n/2, grid);
        Node* bottomRight = solve(row + n/2, col + n/2, n/2, grid);

        Node* node = new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
        return node;
    }

    Node* construct(vector<vector<int>>& grid) {

        int n = grid.size();

        Node* node = solve(0, 0, n, grid);
        return node;
    }
};