// https://leetcode.com/problems/partition-list/submissions/2054248465/?envType=problem-list-v2&envId=linked-list

ListNode* partition(ListNode* head, int x) {
    ListNode* ans = new ListNode(0);
    ListNode* ansmover = ans;
    ListNode* mover = head;
    while(mover!=NULL){
        if(mover->val<x){
            ListNode* newnode = new ListNode(mover->val);
            ansmover->next = newnode;
            ansmover=newnode;
        }
        mover=mover->next;
    }
    mover = head;
    while(mover!=NULL){
        if(mover->val>=x){
            ListNode* newnode = new ListNode(mover->val);
            ansmover->next = newnode;
            ansmover=newnode;
        }
        mover=mover->next;
    }

    return ans->next;
}