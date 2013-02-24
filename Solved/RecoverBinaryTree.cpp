/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//296ms

//some bugs
#include <algorithm>
class Solution {
public:
    TreeNode *prior, *first, *second;
    void find(TreeNode* root) {
        if(root == NULL) return;
        find(root->left);
        if(prior != NULL && prior->val > root->val) {
            if(first == NULL) {
                first = prior;
            }
            second = root;
        }
        prior = root;
        find(root->right);
    }
    void recoverTree(TreeNode *root) {
        first = NULL;
        second = NULL;
        prior = NULL;
        find(root);
        swap(first->val, second->val);
        return;
    }
};