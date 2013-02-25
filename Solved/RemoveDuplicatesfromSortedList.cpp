/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        for(ListNode *p = head; p != NULL; p = p->next) {
            while(p->next != NULL && p->val == p->next->val) {
                int t = p->val;
                while(p->next != NULL && t == p->next->val) p->next = p->next->next;
            }
        }
        return head;
    }
};