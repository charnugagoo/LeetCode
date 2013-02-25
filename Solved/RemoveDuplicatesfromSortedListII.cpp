/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//one bug after fixed idea

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        while(head != NULL && head->next!=NULL && head->val == head->next->val) {
            int t = head->val;
            while(head != NULL && t == head->val) head = head->next; // here, delet head not head->next
        }
        for(ListNode *p = head; p != NULL; p = p->next) {
            while(p->next != NULL && p->next->next != NULL && p->next->val == p->next->next->val) {
                int t = p->next->val;
                while(p->next != NULL && t == p->next->val) p->next = p->next->next;
            }
        }
        return head;
    }
};