#include <bits/stdc++.h>
using namespace std;

ListNode* ans(ListNode* head,int n){

    ListNode* dummy = new ListNode(0);
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    for(int i=0;i<n+1;i++){
        fast = fast->next;
    }

    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }

    slow->next = slow->next->next;

    return dummy->next;
}

int main(){

    return 0;
}