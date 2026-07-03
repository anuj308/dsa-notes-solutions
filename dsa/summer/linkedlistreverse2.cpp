// https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=problem-list-v2&envId=linked-list



 ListNode* reverseBetween(ListNode* head, int left, int right) {

    ListNode* dummy = new ListNode(-600);
    dummy->next = head;
    ListNode* mover = dummy;
    ListNode* startB = NULL;
    ListNode* endA = NULL;
    int i = 0; // as i have dummy start
    while(mover!=NULL){
        if(i==(left-1)){
            startB = mover;
            break;
        } 
        i++;
        mover=mover->next;
    }

    ListNode* prev = NULL;
    ListNode* curr = startB->next;
    ListNode* next = NULL;
    ListNode* startReverse = curr;
    i++; // as in before loop it break not incremented
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        if(i==right){
            endA = curr; // or next same
            break;
        } 
        i++;
    }

    if(startB->val==-600){
        head = prev;
    }else {
        startB->next = prev;
    }

    if(endA!=NULL){
        startReverse->next = endA;
    }


    return head;
}