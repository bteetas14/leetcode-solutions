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
    TreeNode* insertIntoBST(TreeNode* root, int key) {

        if(root == NULL) return new TreeNode(key);

        TreeNode* curr = root;
        while(true){
            if(key > curr->val){
                if(curr->right != NULL){
                    curr = curr->right;
                }
                else{
                    TreeNode* node = new TreeNode(key);
                    curr->right = node;
                    break;
                }
            }
            else{
                if(curr->left != NULL){
                    curr = curr->left;
                }
                else{
                    TreeNode* node = new TreeNode(key);
                    curr->left = node;
                    break;
                }
            }
        }
        return root;
    }
};