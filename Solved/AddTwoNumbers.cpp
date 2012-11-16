//
//  AddTwoNumbers.cpp
//  
//  
//  Created by 于 卓然 on 12-11-15.
//  168ms for large
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int sum = 0, up = 0;
    ListNode* res = NULL;
    ListNode* it = res;
    while(l1!=NULL || l2!=NULL || up!=0) {
        sum += up;
        if(l1!=NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2!=NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        up = sum/10;
        sum %= 10;
        ListNode* temp = new ListNode(sum);
        if(res==NULL) {
            res = temp;
            it = temp;
        }else{
            it->next = temp;
            it = temp;
        }
//        see(sum);
//        see(up);
    }
    return res;
}

int main() {
    int n1, n2, in;
    while(cin>>n1>>n2) {
//        ListNode* temp = new ListNode(0);
        ListNode* num1 = new ListNode(0);
        ListNode* num2 = new ListNode(0);
        ListNode* it1 = num1;
        ListNode* it2 = num2;
        for(int i = 0; i < n1; ++i) {
            cin>>in;
            if(i != 0) {
                ListNode* temp = new ListNode(in);
                it1->next = temp;
                it1 = temp;
            }else{
                it1->val = in;
            }
        }
        for(int i = 0; i < n2; ++i) {
            cin>>in;
            if(i != 0) {
                ListNode* temp = new ListNode(in);
                it2->next = temp;
                it2 = temp;
            }else{
                it2->val = in;
            }
        }
        addTwoNumbers(num1,num2);
    }
    return 0;
}