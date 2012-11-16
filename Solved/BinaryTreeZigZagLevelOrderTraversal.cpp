//
//  BinaryTreeLevelZigZagOrderTraversal.cpp
//  
//
//  Created by 于 卓然 on 12-11-16.
//  1 bug
//  32ms for large

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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if(root==NULL) return res;
        q1.push(root);
        q2.push(0);
        int l = 0;
        vector<int> temp;
        bool rev = true;
        while(!q1.empty()) {
            if(q1.front()->left!=NULL) {q1.push(q1.front()->left);q2.push(q2.front()+1);}
            if(q1.front()->right!=NULL) {q1.push(q1.front()->right);q2.push(q2.front()+1);}
            if(l == q2.front()) {
                temp.push_back(q1.front()->val);
            } else {
                if(rev) {
                    reverse(temp.begin(), temp.end());
                    rev = false;
                } else
                    rev = true;
                res.push_back(temp);
                temp.clear();
                temp.push_back(q1.front()->val);
                l++;
            }
            q1.pop();
            q2.pop();
        }
        if(rev) {
            reverse(temp.begin(), temp.end());
            rev = false;
        }
        res.push_back(temp);
    }
};