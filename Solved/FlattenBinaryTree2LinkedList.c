//
//  FlattenBinaryTree2LinkedList.c
//  
//
//  Created by 于 卓然 on 12-12-13.
//
//
//数组式堆写错了 ToT,,...s[i++], s[--i]
//dfs 先放右再放左

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


TreeNode* s[1000];

class Solution {
public:
    int t;
    void flatten(TreeNode *root) {
        if(root == NULL) return;
        t = 0;
        s[t++] = root;
        TreeNode* it = root;
        while(t>0) {
            TreeNode* now = s[--t];//
            if(now != root) it->right = now;
            it = now;
            if(now->right != NULL) {s[t++] = now->right; now->right = NULL;}
            if(now->left != NULL) {s[t++] = now->left; now->left = NULL;}
        }
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    Solution p;
    p.flatten(root);
    see(root->val);
    see(root->right->val);
}