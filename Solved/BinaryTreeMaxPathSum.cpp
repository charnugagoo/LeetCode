//
//  BinaryTreeMaxPathSum.cpp
//  
//
//  Created by 于 卓然 on 12-11-16.
//
//  Many bugs ToT, there would be negative val in nodes... not only started from leaf...
//  248ms for large

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
    int mp;
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cross = 0, ml = -65536, mr = -65536, res = -65536;
        if(root == NULL) return 0;
        if(root->left != NULL) {
            res = max(res, maxPathSum(root->left));
            ml = mp;
            cross += max(0, ml);
        }
        if(root->right != NULL) {
            res = max(res, maxPathSum(root->right));
            mr = mp;
            cross += max(0, mr);
        }
        res = max(res, root->val + cross);
        mp = max(max(ml, mr), 0) + root->val;
        return res;
    }
};