/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//small bug one
class Solution {
public:
    vector<TreeNode *> generate(int start, int end) {
        vector<TreeNode *> res;
        if(start >= end) {res.push_back(NULL); return res;}
        for(int i = start; i < end; ++i) {
            vector<TreeNode *> ll = generate(start, i);//bug here "start" <- "0"
            vector<TreeNode *> rr = generate(i+1, end);
            for(int j = 0; j < ll.size(); ++j)
                for(int k = 0; k< rr.size(); ++k) {
                    TreeNode* root = new TreeNode(i);
                    root->left = ll[j];
                    root->right = rr[k];
                    res.push_back(root);
                }
        }
        return res;
    }
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n+1);
    }
};