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
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()) {
            TreeNode *l = q1.front();
            TreeNode *r = q2.front();
            q1.pop(); q2.pop();
            if(!l && !r) continue;
            if(!l || !r) return false;
            if(l->val != r->val) return false;
            q1.push(l->left); q2.push(r->right);
            q1.push(l->right); q2.push(r->left);
        }
        return true;
    }
};