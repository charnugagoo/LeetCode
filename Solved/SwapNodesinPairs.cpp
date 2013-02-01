//
//  SwapNodesinPairs.cpp
//  
//
//  Created by 于 卓然 on 13-1-31.
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
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(!head || !(head->next)) return head;
        ListNode* right = head->next->next, *curr1 = head, *curr2 = head->next, *left;
        head->next->next = head;
        head->next = right;
        head = curr2;
        
        while( right!=NULL && right->next!=NULL ) {
            left = curr1;
            curr1 = right;
            curr2 = curr1->next;
            right = curr2->next;
            
            left->next = curr2;
            curr1->next = right;
            curr2->next = curr1;
            
        }
        
        return head;
    }
};