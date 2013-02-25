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
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL) return NULL;
        ListNode *s = new ListNode(0), *st = NULL, *b = new ListNode(0), *bt = NULL;
        for(; head != NULL; head = head->next) {
            if(head->val < x) {
                st->next = head;
                st = head;
            } else {
                bt->next = head;
                bt = head;
            }
        }
        bt->next = NULL;
        st->next = b->next;
        return s->next;
    }
};