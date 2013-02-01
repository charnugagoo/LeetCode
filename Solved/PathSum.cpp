//
//  PathSum.cpp
//  
//
//  Created by 于 卓然 on 13-1-29.
//
//  2 bugs....

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL) {
            if(root->val == sum) return true;
            return false;
        } else {
            bool flag = false;
            if(root->left != NULL) {
                flag = flag || hasPathSum(root->left, sum - root->val);
            }
            if(root->right != NULL) {
                flag = flag || hasPathSum(root->right, sum - root->val);
            }
            return flag;
        }
    }
};