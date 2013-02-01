//
//  PopulatingNextRightPointersinEachNode.cpp
//  
//
//  Created by 于 卓然 on 13-1-31.
//
// good idea by http://blog.unieagle.net/2012/12/24/leetcode-problem-populating-next-right-pointers-in-each-node-level-traversal-of-binary-tree/
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
        queue<TreeLinkNode*> q;
        if(!root) return;
        q.push(root);
        q.push(NULL);
        while(1) {
            TreeLinkNode* curr = q.front();
            q.pop();
            if(curr) {
                curr -> next = q.front();
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            } else {
                if(!q.size()) return;
                q.push(NULL);
            }
        }
    }
};