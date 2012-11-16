//
//  BinaryTreeInorderTraversal.cpp
//  
//
//  Created by 于 卓然 on 12-11-16.
//
//  one mistake
//  16ms in large

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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res, temp;
        if(root == NULL) return res;
        res = inorderTraversal(root->left);
        res.push_back(root->val);
        temp = inorderTraversal(root->right);
        for(int i = 0, l = temp.size(); i < l; ++i) res.push_back(temp[i]);
        return res;
    }
};
