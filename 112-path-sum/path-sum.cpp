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
    bool solve(TreeNode* node, int target){
        if(node->left == nullptr && node->right == nullptr){
            return target == node->val;
        }

        if(node->left!=nullptr && solve(node->left, target-node->val)) return true;;
        if(node->right!=nullptr && solve(node->right, target-node->val)) return true;

        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root==NULL) return false;

        return solve(root, targetSum);
        
    }
};