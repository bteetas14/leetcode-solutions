/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int check(TreeNode* node){
        if(node==NULL) return 0;

        auto lh = check(node->left);
        if(lh==-1) return -1;

        auto rh = check(node->right);
        if(rh==-1) return -1;

        if(abs(lh-rh)>1) return -1;
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {

        if(check(root)==-1) return false;
        return true;
        
    }
};