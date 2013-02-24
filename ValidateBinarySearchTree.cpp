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
    bool check(TreeNode *root, vector<int> &p) {
        if(!root) return true;
        bool flag = true;
        vector<int> p1, p2;
        if(root->left) flag = flag && check(root->left, p1);
        if(root->right) flag = flag && check(root->left, p2);
        if(p1.size() && p1[1] >= root->val) flag = false;
        if(p2.size() && p2[0] <= root->val) flag = false;
        if(p1.size()) p.push_back(p1[0]); else p.push_back(root->val);
        if(p2.size()) p.push_back(p2[1]); else p.push_back(root->val);
        return flag;
    }
    bool isValidBST(TreeNode *root) {
        vector<int> p;
        return check(root, p);
    }
};