//
//  ConvertSortedList2BinarySearchTree.cpp
//  
//
//  Created by 于 卓然 on 12-12-12.
//
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int arr[10000];
class Solution {
public:
    TreeNode *dfs(ListNode* head, int len) {//[0, len)
        if(len <= 0) return NULL;
        ListNode* it = head;
        for(int i = 0; i < len/2; ++i, it = it->next);//len/2
        TreeNode *root = new TreeNode(it->val);
        root->left = dfs(head, len/2);//[0, len/2)
        root->right = dfs(it->next, len - len/2 - 1);//[len/2+1， len)
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        for(ListNode* it = head; it != NULL; it = it->next, len++);
        return dfs(head, len);
    }
};
