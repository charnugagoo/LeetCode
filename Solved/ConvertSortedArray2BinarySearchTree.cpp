//
//  ConvertSortedArray2BinarySearchTree.cpp
//
//
//  Created by 于 卓然 on 12-12-12.
//
//
//why this is wrong?....
//TreeNode a(0);????????????

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int arr[10000];

class Solution {
public:
    TreeNode *dfs(int a, int b) {//[a, b)
        int l = b - a;
        if(l <= 0) return NULL;
        //why this is wrong?....
        //TreeNode a(0);????????????
        TreeNode *root = new TreeNode(arr[(a + b)/2]);
        root->left = dfs(a, (a + b)/2);
        root->right = dfs((a + b)/2+1, b);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        for(int i = 0, l = num.size(); i < l; ++i) arr[i] = num[i];
        return dfs(0, num.size());
    }
};

int main() {
    Solution x;
    vector<int> b;
    int c, d;
    while(cin>>c) {
        b.clear();
        for(int i = 0; i < c; ++i){
            cin>>d;
            b.push_back(d);
        }
        TreeNode* temp = x.sortedArrayToBST(b);
        cout<<temp->val<<endl;
    }
}