//
//  PopulatingNextRightPointersinEachNodeII.cpp
//  
//
//  Created by 于 卓然 on 13-1-31.
//
//
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        while(1) {
            TreeLinkNode* curr = q.front();
            q.pop();
            if(curr) {
                curr -> next = q.front();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            } else {
                if(!q.size()) return;
                q.push(NULL);
            }
        }
    }
};