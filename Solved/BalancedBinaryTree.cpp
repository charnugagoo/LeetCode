//
//  BalancedBinaryTree.cpp
//  
//
//  Created by 于 卓然 on 12-11-15.
//  120ms for large
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int hl, hr;
bool isBalanced(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(root == NULL) {
        hl = -1;
        hr = -1;
        return true;
    }
    
    bool res = true;
    int hhl, hhr;
    res = res && isBalanced(root->left);
    hhl = max(hl, hr) + 1;
    res = res && isBalanced(root->right);
    hhr = max(hl, hr) + 1;

    hl = hhl;
    hr = hhr;
    return res = res && (abs(hl-hr) <= 1);
}