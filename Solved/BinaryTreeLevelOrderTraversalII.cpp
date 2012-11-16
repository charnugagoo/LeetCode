//
//  BinaryTreeLevelOrderTraversalII.cpp
//  
//
//  Created by 于 卓然 on 12-11-16.
//
//  easy by using void reserve(a.begin(), a.end())

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
queue<TreeNode*> q1;
queue<int> q2;
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if(root==NULL) return res;
        q1.push(root);
        q2.push(0);
        int l = 0;
        vector<int> temp;
        while(!q1.empty()) {
            if(q1.front()->left!=NULL) {q1.push(q1.front()->left);q2.push(q2.front()+1);}
            if(q1.front()->right!=NULL) {q1.push(q1.front()->right);q2.push(q2.front()+1);}
            if(l == q2.front()) {
                temp.push_back(q1.front()->val);
            } else {
                res.push_back(temp);
                temp.clear();
                temp.push_back(q1.front()->val);
                l++;
            }
            q1.pop();
            q2.pop();
        }
        res.push_back(temp);
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >res = levelOrder(root);
        reverse(res.begin(), res.end());
        return res;
    }
};