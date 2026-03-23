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
    unordered_map<int, vector<TreeNode*>> mpp;
    vector<TreeNode*> solve(int n){

        if(n%2==0) return {};
        if(n==1){
            TreeNode* n = new TreeNode();
            return {n};
        }

        if(mpp.find(n) != mpp.end()) return mpp[n];

        vector<TreeNode*> result;

        for(int i=1;i<n;i+=2){
            vector<TreeNode*> leftAllFBT = solve(i);
            vector<TreeNode*> rightAllFBT = solve(n-i-1);

            for(auto l:leftAllFBT){
                for(auto r:rightAllFBT){
                    TreeNode* root = new TreeNode();
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return mpp[n] = result;
    }

    vector<TreeNode*> allPossibleFBT(int n) {

        return solve(n);
        
    }
};